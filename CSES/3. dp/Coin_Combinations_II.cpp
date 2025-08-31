#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,x; cin>>n>>x;
    vector<int> coins(n);
    for (auto &c : coins) {
        cin>>c;
    }

    const int MOD =1000000007;
    vector<ll> dp(x+1, 0);
    dp[0]=1;

    for (int c : coins) {
        for (int i = c; i < x+1; ++i) {
            dp[i] = (dp[i] + dp[i-c]) % MOD;
        }
    }
    cout << dp[x];

    return 0;
}