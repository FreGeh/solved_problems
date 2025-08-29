#!/usr/bin/env python3
import subprocess, sys, os, json, math
from pathlib import Path
from datetime import datetime, timedelta, date
from collections import defaultdict, Counter
try:
    from zoneinfo import ZoneInfo
except ImportError:
    # Py3.8 fallback (unlikely on GH-hosted runners)
    from backports.zoneinfo import ZoneInfo  # type: ignore

# -------- Config (from env) --------
REPO_ROOT = Path(subprocess.check_output(["git", "rev-parse", "--show-toplevel"]).decode().strip())
os.chdir(REPO_ROOT)

TARGET_DIRS = [d.strip() for d in os.environ.get("TARGET_DIRS", "CSES,USACO,atcoder,codechef,codeforces").split(",") if d.strip()]
WINDOW_DAYS = int(os.environ.get("WINDOW_DAYS", "91"))
TZ_REGION = os.environ.get("TZ_REGION", "Europe/Berlin")
OUTPUT_SVG = os.environ.get("OUTPUT_SVG", "assets/heatmap.svg")
OUTPUT_JSON = os.environ.get("OUTPUT_JSON", "assets/heatmap_data.json")

# Optional: restrict to certain extensions (leave empty to include all)
ALLOWED_EXTS = {".cpp"}

# SVG layout
CELL = 12         # cell size
GAP = 2           # gap between cells
PAD_LEFT = 40     # room for weekday labels
PAD_TOP = 20      # room for month labels
LEGEND_H = 40     # legend height
FONT_SIZE = 10

GREEN_PALETTE = [
    "#ebedf0",  # 0
    "#c6e48b",  # low
    "#7bc96f",  # mid
    "#239a3b",  # high
    "#196127",  # very high
]

tz = ZoneInfo(TZ_REGION)
today_local = datetime.now(tz).date()
start_date = today_local - timedelta(days=WINDOW_DAYS - 1)  # inclusive

# Snap grid to full weeks (Mon..Sun) so it looks tidy
def week_monday(d: date) -> date:
    return d - timedelta(days=(d.weekday()))  # Monday=0
grid_start = week_monday(start_date)
grid_end = today_local  # inclusive

# Collect all tracked files under TARGET_DIRS (in HEAD)
def ls_files(paths):
    if not paths:
        return []
    args = ["git", "ls-files", "-z", "--"] + paths
    out = subprocess.check_output(args)
    return [p for p in out.decode(errors="ignore").split("\x00") if p]

tracked = []
for d in TARGET_DIRS:
    if (REPO_ROOT / d).exists():
        tracked.extend(ls_files([d]))

# Filter by extension if requested
if ALLOWED_EXTS:
    tracked = [p for p in tracked if Path(p).suffix.lower() in ALLOWED_EXTS]

# For each file, find the first commit date (author date, ISO-8601) that introduced it
# We attribute the file to its current top-level folder.
def first_added_iso(filepath: str) -> str | None:
    try:
        out = subprocess.check_output(
            ["git", "log", "--follow", "--diff-filter=A", "--format=%aI", "-1", "--", filepath],
            stderr=subprocess.DEVNULL,
        )
        s = out.decode().strip()
        return s if s else None
    except subprocess.CalledProcessError:
        return None

def top_folder(path: str) -> str:
    p = Path(path).parts
    return p[0] if p else ""

# Tally additions per local date
date_totals: Counter[date] = Counter()
date_folder_counts: dict[date, Counter[str]] = defaultdict(Counter)

for fp in tracked:
    iso = first_added_iso(fp)
    if not iso:
        continue
    dt = datetime.fromisoformat(iso.replace("Z", "+00:00")).astimezone(tz)
    d = dt.date()
    if start_date <= d <= today_local:
        folder = top_folder(fp)
        date_totals[d] += 1
        date_folder_counts[d][folder] += 1

# Build list of all days in grid range (full weeks)
days = []
cur = grid_start
while cur <= grid_end:
    days.append(cur)
    cur += timedelta(days=1)

# Compute color thresholds based on non-zero distribution for good contrast
nonzeros = sorted([date_totals[d] for d in days if date_totals[d] > 0])
def quantile(xs, q):
    if not xs:
        return 1
    pos = (len(xs)-1) * q
    lo = math.floor(pos); hi = math.ceil(pos)
    if lo == hi: return xs[lo]
    return int(round(xs[lo] + (xs[hi]-xs[lo])*(pos-lo)))

q1 = quantile(nonzeros, 0.25)
q2 = quantile(nonzeros, 0.50)
q3 = quantile(nonzeros, 0.75)
maxv = nonzeros[-1] if nonzeros else 1

def color_for(v: int) -> str:
    if v <= 0: return GREEN_PALETTE[0]
    if v <= max(1, q1): return GREEN_PALETTE[1]
    if v <= max(1, q2): return GREEN_PALETTE[2]
    if v <= max(1, q3): return GREEN_PALETTE[3]
    return GREEN_PALETTE[4]

# Determine grid width in weeks
week_count = ((grid_end - grid_start).days // 7) + 1
width = PAD_LEFT + week_count * (CELL + GAP)
height = PAD_TOP + 7 * (CELL + GAP) + LEGEND_H

# Month labels positions
def first_of_month(d: date) -> date:
    return d.replace(day=1)

month_starts = []
seen = set()
for w in range(week_count):
    xdate = grid_start + timedelta(days=w*7)
    fm = first_of_month(xdate)
    if fm not in seen and fm >= grid_start and fm <= grid_end:
        seen.add(fm)
        month_starts.append((w, fm))

# Build SVG
def esc(s: str) -> str:
    return (s
            .replace("&", "&amp;")
            .replace("<", "&lt;")
            .replace(">", "&gt;")
            .replace('"', "&quot;"))

svg_parts = []
svg_parts.append(f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" viewBox="0 0 {width} {height}" role="img" aria-labelledby="title desc">')
svg_parts.append(f'<title id="title">Competitive Programming Progress - last {WINDOW_DAYS} days</title>')
svg_parts.append(f'<desc id="desc">Each square shows the number of new files first added that day. Hover for folder breakdown.</desc>')

# Month labels
for w, fm in month_starts:
    x = PAD_LEFT + w*(CELL+GAP)
    label = fm.strftime("%b")
    svg_parts.append(f'<text x="{x}" y="{FONT_SIZE}" font-size="{FONT_SIZE}" fill="#555">{label}</text>')

# Weekday labels (Mon, Wed, Fri for compactness)
weekday_labels = {0: "Mon", 2: "Wed", 4: "Fri"}
for r in weekday_labels:
    y = PAD_TOP + r*(CELL+GAP) + CELL - 2
    svg_parts.append(f'<text x="0" y="{y}" font-size="{FONT_SIZE}" fill="#777">{weekday_labels[r]}</text>')

# Cells
for idx, d in enumerate(days):
    week = (d - grid_start).days // 7
    dow  = d.weekday()  # 0=Mon
    x = PAD_LEFT + week * (CELL + GAP)
    y = PAD_TOP + dow * (CELL + GAP)
    v = date_totals[d]
    fill = color_for(v)

    # Tooltip text
    if v == 0:
        tip = f"{d.isoformat()} • no new files"
    else:
        buckets = date_folder_counts[d]
        items = sorted(((fld, cnt) for fld, cnt in buckets.items() if cnt > 0),
                       key=lambda x: (-x[1], x[0].lower()))
        lines = [f"{d.isoformat()} • {v} file(s)"]
        for fld, cnt in items:
            lines.append(f"{fld}: {cnt}")
        tip = "\n".join(lines)

    svg_parts.append(f'<rect x="{x}" y="{y}" width="{CELL}" height="{CELL}" rx="2" ry="2" fill="{fill}">')
    svg_parts.append(f'  <title>{esc(tip)}</title>')
    svg_parts.append('</rect>')

# Legend
legend_x = PAD_LEFT
legend_y = PAD_TOP + 7*(CELL+GAP) + 14
legend_vals = [0, max(1, q1), max(1, q2), max(1, q3), maxv]
svg_parts.append(f'<text x="{legend_x}" y="{legend_y-6}" font-size="{FONT_SIZE}" fill="#555">Intensity</text>')

lx = legend_x
for i, val in enumerate(legend_vals):
    svg_parts.append(f'<rect x="{lx}" y="{legend_y}" width="{CELL}" height="{CELL}" rx="2" ry="2" fill="{GREEN_PALETTE[i]}"><title>≈ {val}</title></rect>')
    lx += CELL + 4
svg_parts.append(f'<text x="{lx+4}" y="{legend_y+CELL-2}" font-size="{FONT_SIZE}" fill="#777">{start_date.isoformat()} → {today_local.isoformat()}</text>')

svg_parts.append('</svg>')
svg = "\n".join(svg_parts)

# Ensure output dir
out_svg_path = REPO_ROOT / OUTPUT_SVG
out_svg_path.parent.mkdir(parents=True, exist_ok=True)
out_svg_path.write_text(svg, encoding="utf-8")

# Save data for debugging/inspection
data = {
    "config": {
        "target_dirs": TARGET_DIRS,
        "window_days": WINDOW_DAYS,
        "timezone": TZ_REGION,
        "start_date": start_date.isoformat(),
        "today": today_local.isoformat(),
        "grid_start": grid_start.isoformat(),
        "grid_weeks": week_count,
        "q1": q1, "q2": q2, "q3": q3, "max": maxv,
    },
    "per_day": {
        d.isoformat(): {
            "total": date_totals[d],
            "by_folder": dict(date_folder_counts[d])
        }
        for d in days
    }
}
(REPO_ROOT / OUTPUT_JSON).write_text(json.dumps(data, indent=2), encoding="utf-8")
print(f"Wrote {OUTPUT_SVG} and {OUTPUT_JSON}")
