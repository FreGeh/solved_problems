#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;cin>>n;
    const int INF = INT_MAX;
    vector<int> dp(n+1, INF);
    dp[0]=0;

    for (int i=1; i<n+1; i++) {
        int x = i;
        while (x) { //!=0
            int d = x % 10;
            if (d) { //!=0
                dp[i] = min(dp[i], dp[i - d] + 1);
            }
            x /= 10;
        }
    }
    cout<<dp[n];
    return 0;
}
