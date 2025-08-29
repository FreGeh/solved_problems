#include "bits/stdc++.h"
using namespace std;
#define ll long long

// Conditional compilation
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) do { } while(0)
#endif

void solve() {
    int n;
    cin >> n;
    const double INF = 1e18;

    std::vector<std::pair<int, int>> towns(n);
    for (auto &t : towns) {
        cin >> t.first >> t.second;
    }

    vector<vector<double>> dist(n, vector<double>(n, INF));
    for (int i = 0; i < n; ++i)
    {
        dist[i][i] = 0;
        for (int j = i + 1; j < n; ++j)
        {
            double dx = towns[i].first - towns[j].first;
            double dy = towns[i].second - towns[j].second;
            double d = sqrt(dx * dx + dy * dy);
            if (dx==0 && dy==0) {
                d = 0;
            }
            if (d <= 10.0)
            {
                dist[i][j] = dist[j][i] = d;
            }
        }
    }

    // floyd
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    double worst = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (dist[i][j] >= INF / 2)
            {
                cout << "Send Kurdy\n";
                return;
            }
            worst = max(worst, dist[i][j]);
        }
    }

    cout << fixed << setprecision(8) << worst << endl;
}

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0) solve();

    return 0;
}
