#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    ll n; cin>>n;
    vector<ll> dp(n+1);
    dp[0]=1;
    for (int i=1;i<n+1;i++) {
        ll sum = 0;
        for (int j=1;j<=6;j++) {
            if (i-j>=0) {
                sum+=(dp[i-j] % 1000000007);
            }
        }
        dp[i]=sum % 1000000007;
    }
    cout << dp[n];

    return 0;
}

// dont forget to use ll