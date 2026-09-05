/**
 *      author:  gemtec
 *      created: 05.09.2026 16:45:30
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
  int n,k; cin>>n>>k;
  string s; cin>>s;
  vector<bool> done(n/k);
  ll built=0;
  for (int i=0;i<n;i++) {
    if (s[i]=='0' && !done[i/k]) {
      built++;
      done[i/k]=true;
    }
  }
  cout<<n/k-built<<endl;
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