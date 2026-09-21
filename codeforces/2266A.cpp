/**
 *      author:  gemtec
 *      created: 21.09.2026 16:35:32
 *      link:
 *      idea:
 *      learning:
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
  int a,b,c; cin>>a>>b>>c;
  cout<<n-min(min(a,b),c)<<endl;
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