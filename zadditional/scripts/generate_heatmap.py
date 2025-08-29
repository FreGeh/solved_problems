#!/usr/bin/env python3
import subprocess, os, json, math
from pathlib import Path
from datetime import datetime, timedelta, date
from collections import defaultdict, Counter

try:
    from zoneinfo import ZoneInfo
except ImportError:
    from backports.zoneinfo import ZoneInfo  # type: ignore

# -------- Config (from env) --------
REPO_ROOT = Path(subprocess.check_output(["git", "rev-parse", "--show-toplevel"]).decode().strip())
os.chdir(REPO_ROOT)

TARGET_DIRS = [d.strip() for d in os.environ.get("TARGET_DIRS", "CSES,USACO,atcoder,codechef,codeforces").split(",") if d.strip()]
WINDOW_DAYS = int(os.environ.get("WINDOW_DAYS", "365"))
TZ_REGION = os.environ.get("TZ_REGION", "Europe/Berlin")

OUTPUT_SVG_YEAR   = os.environ.get("OUTPUT_SVG_YEAR", "zadditional/heatmap_year.svg")
OUTPUT_DASHBOARD  = os.environ.get("OUTPUT_DASHBOARD", "zadditional/progress_dashboard.svg")
OUTPUT_JSON       = os.environ.get("OUTPUT_JSON", "zadditional/heatmap_data.json")
OUTPUT_HTML       = os.environ.get("OUTPUT_HTML", "zadditional/docs/progress.html")

# extensions filter
exts_env = os.environ.get("ALLOWED_EXTS", "").strip()
ALLOWED_EXTS = set([e.strip().lower() for e in exts_env.split(",") if e.strip()])  # e.g. {".cpp",".py"}

# ---- Aesthetics / layout (year heatmap tuned to be wider like Codeforces) ----
CELL = 13        # square size
GAP = 3          # spacing
PAD_LEFT = 36    # y-axis labels gutter
PAD_TOP = 18     # month labels gutter
LEGEND_H = 28    # legend block
FONT_SIZE = 20
FONT_FAMILY = "system-ui,-apple-system,Segoe UI,Roboto,Ubuntu,Cantarell,Noto Sans,sans-serif"

GREEN_PALETTE = [
    "#ebedf0",  # 0
    "#c6e48b",  # low
    "#7bc96f",  # mid
    "#239a3b",  # high
    "#196127",  # very high
]

# -------- Time helpers --------
tz = ZoneInfo(TZ_REGION)
today_local = datetime.now(tz).date()
start_date_window = today_local - timedelta(days=WINDOW_DAYS - 1)  # inclusive

def week_monday(d: date) -> date:
    return d - timedelta(days=d.weekday())  # Monday = 0

grid_start = week_monday(start_date_window)
grid_end = today_local  # inclusive

# -------- Git helpers --------
def ls_files(paths):
    if not paths:
        return []
    args = ["git", "ls-files", "-z", "--"] + paths
    out = subprocess.check_output(args)
    return [p for p in out.decode(errors="ignore").split("\x00") if p]

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

# -------- Collect repository data (all-time) --------
tracked = []
for d in TARGET_DIRS:
    if (REPO_ROOT / d).exists():
        tracked.extend(ls_files([d]))

if ALLOWED_EXTS:
    tracked = [p for p in tracked if Path(p).suffix.lower() in ALLOWED_EXTS]

# Map each tracked file to its first-add date and current top-level folder
file_births: list[tuple[date, str]] = []
for fp in tracked:
    iso = first_added_iso(fp)
    if not iso:
        continue
    dt = datetime.fromisoformat(iso.replace("Z", "+00:00")).astimezone(tz)
    file_births.append((dt.date(), top_folder(fp)))

# All-time per-day tallies
alltime_totals: Counter[date] = Counter()
alltime_by_folder: dict[date, Counter[str]] = defaultdict(Counter)
for d, folder in file_births:
    alltime_totals[d] += 1
    alltime_by_folder[d][folder] += 1

# Windowed (last 12 months) tallies used for the heatmap
year_totals: Counter[date] = Counter()
year_by_folder: dict[date, Counter[str]] = defaultdict(Counter)
for d, folder in file_births:
    if start_date_window <= d <= today_local:
        year_totals[d] += 1
        year_by_folder[d][folder] += 1

# Build list of all days in the year grid
days = []
cur = grid_start
while cur <= grid_end:
    days.append(cur)
    cur += timedelta(days=1)

# -------- Color scale (quantiles from year data) --------
nonzeros = sorted([year_totals[d] for d in days if year_totals[d] > 0])

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

# -------- Stats (Codeforces-style) --------
def sum_between(totals: Counter[date], start: date, end: date) -> int:
    s = 0
    cur = start
    while cur <= end:
        s += totals[cur]
        cur += timedelta(days=1)
    return s

def longest_streak(totals: Counter[date], start: date, end: date) -> int:
    cur = start
    run = 0
    best = 0
    while cur <= end:
        if totals[cur] > 0:
            run += 1
            if run > best: best = run
        else:
            run = 0
        cur += timedelta(days=1)
    return best

all_time_total = len(file_births)
year_total = sum_between(alltime_totals, today_local - timedelta(days=364), today_local)
month_total = sum_between(alltime_totals, today_local - timedelta(days=29), today_local)

# streak ranges
if file_births:
    earliest = min(d for d, _ in file_births)
else:
    earliest = today_local

streak_all_time = longest_streak(alltime_totals, earliest, today_local)
streak_year = longest_streak(alltime_totals, today_local - timedelta(days=364), today_local)
streak_month = longest_streak(alltime_totals, today_local - timedelta(days=29), today_local)

# -------- SVG builders --------
def esc(s: str) -> str:
    return (s.replace("&", "&amp;")
             .replace("<", "&lt;")
             .replace(">", "&gt;")
             .replace('"', "&quot;"))

def month_starts_between(start: date, end: date):
    res = []
    seen = set()
    days_span = (end - start).days
    week_count = (days_span // 7) + 1
    for w in range(week_count):
        xdate = start + timedelta(days=w*7)
        fm = xdate.replace(day=1)
        if fm not in seen and start <= fm <= end:
            seen.add(fm)
            res.append((w, fm))
    return res

def render_year_heatmap_svg(title: str) -> str:
    week_count = ((grid_end - grid_start).days // 7) + 1
    width = PAD_LEFT + week_count * (CELL + GAP)
    height = PAD_TOP + 7 * (CELL + GAP) + LEGEND_H

    ms = month_starts_between(grid_start, grid_end)

    parts = []
    parts.append(f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" viewBox="0 0 {width} {height}" role="img" aria-labelledby="title desc">')
    parts.append(f'<title id="title">{esc(title)}</title>')
    parts.append(f'<desc id="desc">Each square shows the number of new files first added that day. Open the interactive page for hover details.</desc>')
    parts.append(f'<style>text{{font-family:{FONT_FAMILY};font-size:{FONT_SIZE}px;}}</style>')

    # Month labels
    for w, fm in ms:
        x = PAD_LEFT + w*(CELL+GAP)
        label = fm.strftime("%b")
        parts.append(f'<text x="{x}" y="{FONT_SIZE+2}" fill="#555">{label}</text>')

    # Weekday labels (Mon, Wed, Fri for compact display)
    weekday_labels = {0: "Mon", 2: "Wed", 4: "Fri"}
    for r in weekday_labels:
        y = PAD_TOP + r*(CELL+GAP) + CELL - 2
        parts.append(f'<text x="0" y="{y}" fill="#777">{weekday_labels[r]}</text>')

    # Cells
    for d in days:
        week = (d - grid_start).days // 7
        dow  = d.weekday()
        x = PAD_LEFT + week * (CELL + GAP)
        y = PAD_TOP + dow  * (CELL + GAP)
        v = year_totals[d]
        fill = color_for(v)

        # Tooltip text (works when opening the SVG directly)
        if v == 0:
            tip = f"{d.isoformat()} • no new files"
        else:
            buckets = year_by_folder[d]
            items = sorted(((fld, cnt) for fld, cnt in buckets.items() if cnt > 0),
                           key=lambda x: (-x[1], x[0].lower()))
            lines = [f"{d.isoformat()} • {v} file(s)"]
            for fld, cnt in items:
                lines.append(f"{fld}: {cnt}")
            tip = "\n".join(lines)

        parts.append(f'<rect x="{x}" y="{y}" width="{CELL}" height="{CELL}" rx="2" ry="2" fill="{fill}"><title>{esc(tip)}</title></rect>')

    # Legend
    legend_x = PAD_LEFT
    legend_y = PAD_TOP + 7*(CELL+GAP) + 14
    legend_vals = [0, max(1, q1), max(1, q2), max(1, q3), maxv]
    parts.append(f'<text x="{legend_x}" y="{legend_y-6}" fill="#555">Intensity</text>')
    lx = legend_x
    for i, val in enumerate(legend_vals):
        parts.append(f'<rect x="{lx}" y="{legend_y}" width="{CELL}" height="{CELL}" rx="2" ry="2" fill="{GREEN_PALETTE[i]}"><title>≈ {val}</title></rect>')
        lx += CELL + 4
    parts.append(f'<text x="{lx+4}" y="{legend_y+CELL-2}" fill="#777">{start_date_window.isoformat()} → {today_local.isoformat()}</text>')

    parts.append('</svg>')
    return "\n".join(parts)

def render_dashboard_svg() -> str:
    # Put stats under the heatmap in a 3x2 grid
    week_count = ((grid_end - grid_start).days // 7) + 1
    heatmap_width = PAD_LEFT + week_count * (CELL + GAP)
    heatmap_height = PAD_TOP + 7 * (CELL + GAP) + LEGEND_H

    # Stats block layout
    STAT_COLS = 3
    STAT_ROWS = 2
    STAT_CELL_W = heatmap_width // STAT_COLS
    STAT_LINE1 = 24  # large number
    STAT_LINE2 = 14  # caption

    stats_h = STAT_ROWS * 60 + 12
    width = heatmap_width
    height = heatmap_height + stats_h

    def stat_block(x, y, big, small):
        return (f'<text x="{x}" y="{y}" font-size="{STAT_LINE1}" font-weight="600">{big}</text>'
                f'<text x="{x}" y="{y+22}" fill="#555" font-size="{STAT_LINE2}">{small}</text>')

    parts = []
    parts.append(f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" viewBox="0 0 {width} {height}" role="img" aria-labelledby="t d">')
    parts.append(f'<title id="t">Competitive Programming Progress (last 12 months)</title>')
    parts.append(f'<desc id="d">Daily additions and summary statistics. Click to open interactive version in docs/.</desc>')
    parts.append(f'<style>text{{font-family:{FONT_FAMILY};}}</style>')

    # Embed heatmap body
    parts.append(render_year_heatmap_svg(""))

    # Stats text (overlay)
    y0 = heatmap_height + 34
    xpad = 12
    blocks = [
        (0, 0, f"{all_time_total} problems", "solved for all time"),
        (1, 0, f"{year_total} problems", "solved for the last year"),
        (2, 0, f"{month_total} problems", "solved for the last month"),
        (0, 1, f"{streak_all_time} days", "in a row max."),
        (1, 1, f"{streak_year} days", "in a row for the last year"),
        (2, 1, f"{streak_month} days", "in a row for the last month"),
    ]
    for cx, cy, big, small in blocks:
        x = cx*STAT_CELL_W + xpad
        y = y0 + cy*60
        parts.append(stat_block(x, y, big, small))

    parts.append('</svg>')
    return "\n".join(parts)

# -------- Render assets --------
year_svg = render_year_heatmap_svg(f"Competitive Programming Progress - last {WINDOW_DAYS} days")
(REPO_ROOT / OUTPUT_SVG_YEAR).parent.mkdir(parents=True, exist_ok=True)
(REPO_ROOT / OUTPUT_SVG_YEAR).write_text(year_svg, encoding="utf-8")

dashboard_svg = render_dashboard_svg()
(REPO_ROOT / OUTPUT_DASHBOARD).write_text(dashboard_svg, encoding="utf-8")

# -------- Data JSON (for debugging / external uses) --------
data = {
    "config": {
        "target_dirs": TARGET_DIRS,
        "timezone": TZ_REGION,
        "window_days": WINDOW_DAYS,
        "start_date_window": start_date_window.isoformat(),
        "today": today_local.isoformat(),
        "grid_start": grid_start.isoformat(),
        "grid_weeks": ((grid_end - grid_start).days // 7) + 1,
        "q1": q1, "q2": q2, "q3": q3, "max": maxv,
        "palette": GREEN_PALETTE,
        "cell": CELL, "gap": GAP, "pad_left": PAD_LEFT, "pad_top": PAD_TOP,
    },
    "totals": {
        "all_time_total": all_time_total,
        "year_total": year_total,
        "month_total": month_total,
        "streak_all_time": streak_all_time,
        "streak_year": streak_year,
        "streak_month": streak_month,
    },
    "per_day_year": { d.isoformat(): {"total": year_totals[d], "by_folder": dict(year_by_folder[d])} for d in days },
    "per_day_all": { d.isoformat(): {"total": alltime_totals[d], "by_folder": dict(alltime_by_folder[d])} for d in sorted(alltime_totals) },
}
(REPO_ROOT / OUTPUT_JSON).write_text(json.dumps(data, indent=2), encoding="utf-8")

# -------- Interactive HTML (self-contained) --------
# Inline JSON to avoid fetch/CORS/base-path hassles.
html = f"""<!doctype html>
<meta charset="utf-8">
<title>CP Progress Dashboard</title>
<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
  :root {{
    --fg:#24292e; --muted:#57606a; --grid0:#ebedf0; --bg:#fff;
  }}
  html,body {{ margin:0; padding:0; background:var(--bg); color:var(--fg); font-family:{FONT_FAMILY}; }}
  .wrap {{ max-width: 1200px; margin: 24px auto; padding: 0 16px; }}
  h1 {{ font-size: 20px; margin: 0 0 12px; }}
  .legend {{ font-size: 12px; color: var(--muted); margin-top: 6px; }}
  #tooltip {{
    position: fixed; pointer-events: none; background: #111; color:#fff;
    padding: 6px 8px; border-radius: 6px; font-size: 12px; line-height: 1.35;
    box-shadow: 0 4px 16px rgba(0,0,0,.25); z-index: 10; opacity: 0; transition: opacity .08s ease;
    white-space: pre; max-width: 60vw;
  }}
  .stats {{ display:grid; grid-template-columns: repeat(3, 1fr); gap: 8px 24px; margin-top: 16px; }}
  .stat .big {{ font-weight: 700; font-size: 22px; }}
  .stat .cap {{ color: var(--muted); font-size: 14px; }}
  @media (max-width: 820px) {{
    .stats {{ grid-template-columns: 1fr; }}
  }}
</style>

<div class="wrap">
  <h1>Competitive Programming Progress — last 12 months</h1>
  <div id="heatmap"></div>
  <div class="legend">Hover squares for total and folder breakdown • {esc(start_date_window.isoformat())} → {esc(today_local.isoformat())}</div>

  <div class="stats" id="stats"></div>
</div>

<div id="tooltip"></div>

<script id="data" type="application/json">{json.dumps(data, separators=(',',':'))}</script>
<script>
(function() {{
  const DATA = JSON.parse(document.getElementById('data').textContent);
  const cfg = DATA.config, totals = DATA.totals, per = DATA.per_day_year;
  const cell = cfg.cell, gap = cfg.gap, padL = cfg.pad_left, padT = cfg.pad_top;
  const weeks = cfg.grid_weeks;
  const width = padL + weeks * (cell + gap);
  const height = padT + 7 * (cell + gap) + 28;

  const palette = cfg.palette;
  const q1 = DATA.config.q1, q2 = DATA.config.q2, q3 = DATA.config.q3, vmax = DATA.config.max;

  function colorFor(v) {{
    if (v <= 0) return palette[0];
    if (v <= Math.max(1, q1)) return palette[1];
    if (v <= Math.max(1, q2)) return palette[2];
    if (v <= Math.max(1, q3)) return palette[3];
    return palette[4];
  }}

  const svg = document.createElementNS("http://www.w3.org/2000/svg","svg");
  svg.setAttribute("width", width);
  svg.setAttribute("height", height);
  svg.setAttribute("viewBox", `0 0 ${{width}} ${{height}}`);
  const g = document.createElementNS(svg.namespaceURI, "g");
  svg.appendChild(g);

  // Month labels
  (function monthLabels(){{
    const start = new Date(cfg.grid_start);
    for (let w=0; w<weeks; w++) {{
      const xDate = new Date(start); xDate.setDate(xDate.getDate() + w*7);
      const fm = new Date(xDate.getFullYear(), xDate.getMonth(), 1);
      const key = `${{fm.getFullYear()}}-${{fm.getMonth()}}`;
      if (!monthLabels.seen) monthLabels.seen = new Set();
      if (!monthLabels.seen.has(key) && fm >= new Date(cfg.grid_start) && fm <= new Date(DATA.config.today)) {{
        monthLabels.seen.add(key);
        const x = padL + w*(cell+gap);
        const t = document.createElementNS(svg.namespaceURI, 'text');
        t.setAttribute('x', x);
        t.setAttribute('y', 12);
        t.setAttribute('fill', '#555');
        t.textContent = fm.toLocaleString(undefined, {{month:'short'}});
        g.appendChild(t);
      }}
    }}
  }})();

  // Weekday labels
  const weekdays = {{0:'Mon',2:'Wed',4:'Fri'}};
  for (const k of Object.keys(weekdays)) {{
    const r = +k;
    const t = document.createElementNS(svg.namespaceURI, 'text');
    t.setAttribute('x', 0);
    t.setAttribute('y', padT + r*(cell+gap) + cell - 2);
    t.setAttribute('fill', '#777');
    t.textContent = weekdays[r];
    g.appendChild(t);
  }}

  // Cells
  const startD = new Date(cfg.grid_start), today = new Date(DATA.config.today);
  const msPerDay = 86400000;
  const tooltip = document.getElementById('tooltip');

  function showTip(x,y,text) {{
    tooltip.textContent = text;
    tooltip.style.left = (x + 14) + 'px';
    tooltip.style.top = (y + 14) + 'px';
    tooltip.style.opacity = 1;
  }}
  function hideTip() {{ tooltip.style.opacity = 0; }}

  for (let d = new Date(startD), i=0; d <= today; d = new Date(d.getTime()+msPerDay), i++) {{
    const week = Math.floor((d - startD)/msPerDay/7);
    const dow = (d.getDay()+6)%7; // Mon=0
    const x = padL + week*(cell+gap);
    const y = padT + dow*(cell+gap);

    const key = d.toISOString().slice(0,10);
    const sum = per[key] ? per[key].total : 0;
    const rect = document.createElementNS(svg.namespaceURI, 'rect');
    rect.setAttribute('x', x);
    rect.setAttribute('y', y);
    rect.setAttribute('width', cell);
    rect.setAttribute('height', cell);
    rect.setAttribute('rx', 2);
    rect.setAttribute('ry', 2);
    rect.setAttribute('fill', colorFor(sum));

    rect.addEventListener('mousemove', (ev) => {{
      let text = key + (sum? ` • ${{sum}} file(s)`: ' • no new files');
      if (sum && per[key] && per[key].by_folder) {{
        const pairs = Object.entries(per[key].by_folder).filter(([,v])=>v>0).sort((a,b)=>b[1]-a[1] || a[0].localeCompare(b[0]));
        for (const [f,c] of pairs) text += `\\n${{f}}: ${{c}}`;
      }}
      showTip(ev.clientX, ev.clientY, text);
    }});
    rect.addEventListener('mouseleave', hideTip);

    g.appendChild(rect);
  }}

  document.getElementById('heatmap').appendChild(svg);

  // Stats
  const stats = [
    [ `${{totals.all_time_total}} problems`, 'solved for all time' ],
    [ `${{totals.year_total}} problems`, 'solved for the last year' ],
    [ `${{totals.month_total}} problems`, 'solved for the last month' ],
    [ `${{totals.streak_all_time}} days`, 'in a row max.' ],
    [ `${{totals.streak_year}} days`, 'in a row for the last year' ],
    [ `${{totals.streak_month}} days`, 'in a row for the last month' ],
  ];
  const statsEl = document.getElementById('stats');
  for (const [big,cap] of stats) {{
    const div = document.createElement('div');
    div.className = 'stat';
    const b = document.createElement('div'); b.className = 'big'; b.textContent = big;
    const c = document.createElement('div'); c.className = 'cap'; c.textContent = cap;
    div.appendChild(b); div.appendChild(c);
    statsEl.appendChild(div);
  }}
}})();
</script>
"""

(REPO_ROOT / OUTPUT_HTML).parent.mkdir(parents=True, exist_ok=True)
(REPO_ROOT / OUTPUT_HTML).write_text(html, encoding="utf-8")

print(f"Wrote:\n- {OUTPUT_SVG_YEAR}\n- {OUTPUT_DASHBOARD}\n- {OUTPUT_JSON}\n- {OUTPUT_HTML}")
