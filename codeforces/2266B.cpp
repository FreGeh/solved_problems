/**
 *      author:  gemtec
 *      created: 21.09.2026 16:40:54
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
  ll a,b,c;cin>>a>>b>>c;
  ll score =0;
  if (abs(a+c-b) < abs(a-b)) {
    score = abs(a-b);
  } else {
    score = abs(a+c-b);
  }
  cout<<score<<endl;
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