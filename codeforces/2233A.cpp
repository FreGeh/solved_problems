/**
 *      author:  gemtec
 *      created: 09.06.2026 16:36:50
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
  int n,x,y,z; cin>>n>>x>>y>>z;
  ll sum_n = 0, sum_ai=0;
  int ai = 0;
  int hour=0;
  while ((sum_n < n) && (sum_ai < n)) {
    hour++;
    sum_n+=x; sum_n+=y; sum_ai+=x;
    if (ai<z) ai++;
    else sum_ai+=10*y;
  }
  cout<<hour<<endl;
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