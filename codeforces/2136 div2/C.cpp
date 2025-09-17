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
    int n; cin>>n;
    vector<int> A(n);
    vector<vector<int>> pos(n+1);
    for (int i=0;i<n;i++) {
        cin>>A[i];
        pos[A[i]].push_back(i);
    }

    vector<tuple<int,int,int>> interval;
    for (int val=1;val<=n;val++) {
        int count=pos[val].size();
        if (count>=val) {
            for (int j=0;j+val-1<count;j++) {
                int l=pos[val][j];
                int r=pos[val][j+val-1];
                interval.push_back({l,r,val});
            }
        }
    }

    sort(interval.begin(), interval.end(), [](const auto &x, const auto &y) {
        auto [l1, r1, w1] = x;
        auto [l2, r2, w2] = y;
        if (r1 != r2) return r1 < r2;
        return l1 < l2;
    });

    int m = (int)interval.size();
    if (m == 0) {
        cout << 0 << "\n";
        return;
    }

    vector<int> ends(m);
    for (int i = 0; i < m; ++i) {
        auto [l, r, w] = interval[i]; 
        ends[i] = r;
    }

    vector<int> dp(m);
    for (int i = 0; i < m; ++i) {
        auto [l_i, r_i, w_i] = interval[i]; 
        int prev_id = -1;
        auto it = upper_bound(ends.begin(), ends.begin() + i, l_i - 1);
        if (it != ends.begin()) prev_id = (it - ends.begin()) - 1;

        int take = w_i + (prev_id == -1 ? 0 : dp[prev_id]);
        int notake = (i == 0 ? 0 : dp[i-1]);
        dp[i] = max(notake, take);
    }
    cout << dp[m-1]<<"\n";
}

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    int tests; cin >> tests;
    while (tests-- > 0) solve();
    return 0;
}
