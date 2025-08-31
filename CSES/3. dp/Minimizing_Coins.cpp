#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,x;
    cin>>n>>x;
    const int INF=x+1;
    vector<int> coins(n);
    for (auto &c : coins) {
        cin>>c;
    }

    vector<int> dp(x+1, INF);
    dp[0]=0;
    for (int i=1;i<=x;i++) {
        for (int c : coins) {
            if (c <= i) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    cout << (dp[x]>x ? -1 : dp[x]) <<"\n";
    return 0;
}
