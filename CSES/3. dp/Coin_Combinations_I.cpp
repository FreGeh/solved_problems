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

    for (int i=1;i<x+1;i++) {
        ll sum = 0;
        for (auto c : coins) {
            if (i-c>=0) {
                sum+=(dp[i-c] % MOD);
            }
        }
        dp[i]=sum % MOD;
    }
    cout << dp[x];

    return 0;
}