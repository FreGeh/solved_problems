/**
 *      author:  gemtec
 *      created: 14.03.2026 16:52:14
 *      link:
 *      idea:
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

void solve() {
    int n; cin>>n;
    vector<pair<int,int>> tasks(n);
    for (int i=0; i<n;i++) {
        int c,p; cin>>c>>p;
        tasks[i]={c,p};
    }
    vector<double> dp(n+1,0.0);
    for (int i=n-1; i>=0;i--) {
        dp[i]=max(dp[i+1], tasks[i].first + (dp[i+1]*(100.0 - (tasks[i].second))/100.0));
    }
    cout<<fixed<<setprecision(10)<<dp[0]<<"\n";
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