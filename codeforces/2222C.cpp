/**
 *      author:  gemtec
 *      created: 25.04.2026 17:59:34
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
  vector<int> A(n);
  for (int i=0;i<n;i++) {
    cin>>A[i];
  }
  vector<int> B = A;
  sort(B.begin(),B.end());
  int med=B[n/2];

  vector<int> dp(n+1,INT_MIN);
  dp[0]=0;

  for (int i=1;i<=n;i++) {
    ll less=0;
    ll great=0;
    for (int j=i-1;j>=0;j--) {
      if (A[j]>med) great++;
      if (A[j]<med) less++;
      int cur = i-j;
      if (cur%2!=0 && great <= cur/2 && less <= cur/2) {
        dp[i]=max(dp[i],dp[j]+1);
      }
    }
  }
  cout<<dp[n]<<"\n";
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