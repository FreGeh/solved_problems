/**
 * author:  gemtec
 * created: 03.03.2026 15:06:07
 * link:
 * idea:
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

struct Pass{
    int active_days,usable_days,cost;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<pair<int, int>> brewing(n);
    for (int i=0; i<n;i++) {
        cin>>brewing[i].first>>brewing[i].second;
    }
    vector<Pass> passes(k);
    for (int i = 0; i < k; i++) {
        int p,d,c;
        cin>>p>>d>>c;
        passes[i]={p,d,c};
    }

    vector<ll> dp(n+1, LLONG_MAX);
    dp[0] = 0;
    for (int i=1; i<=n; i++) {
        dp[i] = dp[i-1] + brewing[i-1].second;
        for (auto &p : passes) {
            int start_limit_day = brewing[i-1].first-p.active_days+1;
            auto it = lower_bound(brewing.begin(),brewing.begin()+i,make_pair(start_limit_day, -1));
            int firstid = distance(brewing.begin(), it);
            int fromid = max(firstid, i-p.usable_days);
            
            dp[i] = min(dp[i], dp[fromid] + p.cost);
        }
    }
    cout << dp[n] << "\n";
    return 0;
}