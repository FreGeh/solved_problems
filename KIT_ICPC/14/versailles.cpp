#include "bits/stdc++.h"
using namespace std;
#define ll long long

// Conditional compilation
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) \
    do             \
    {              \
    } while (0)
#endif

using pt = pair<ll,ll>;

struct PtHash {
    size_t operator()(const pt& p) const {
        return hash<ll>()(p.first) ^ (hash<ll>()(p.second) << 1);
    }
};

pt operator-(const pt& a, const pt& b) {
    return {a.first - b.first, a.second - b.second};
}

ll cross(const pt& a, const pt& b) {
    return a.first * b.second - a.second * b.first;
}

int64_t ccw(pt a, pt b, pt c)
{
    return cross(b - a, c - a);
}
vector<pt> hull(vector<pt> &pts)
{
    sort(pts.begin(), pts.end());
    auto half_hull = [](auto begin, auto end)
    {
        vector<pt> res(end - begin);
        int64_t k = 0;
        for (auto it = begin; it != end; ++it)
        {
            while (k >= 2 && ccw(res[k - 2], res[k - 1], *it) < 0)
                --k;
            res[k++] = *it;
        }
        res.resize(k);
        return res;
    };
    vector<pt> lower = half_hull(pts.begin(), pts.end());   // Vorwaerts .
    vector<pt> upper = half_hull(pts.rbegin(), pts.rend()); // Rueckwaerts .
    if (lower.size() == 1)
        return lower; // Sonderfall : Einzelner Punkt .
    lower.insert(lower.end(), next(upper.begin()), prev(upper.end()));
    return lower;
};

void solve()
{
    int n;
    cin >> n;
    vector<pt> pts(n);
    for (auto &pt : pts)
    {
        int x,y; cin >> x >> y;
        pt.first = x;
        pt.second =y;
    }
    int count=0;
    while (!pts.empty()) {
        vector<pt> circle = hull(pts);
        // remove circle from pts
        unordered_set<pt, PtHash> circle_set(circle.begin(), circle.end());
        pts.erase(remove_if(pts.begin(), pts.end(),
            [&](const pt &p) { return circle_set.count(p); }),
            pts.end());
        count++;
    }
    cout << count << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        solve();

    return 0;
}
