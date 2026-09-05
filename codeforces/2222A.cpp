/**
 *      author:  gemtec
 *      created: 25.04.2026 16:34:37
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
  int n;
  cin>>n;
  vector<int> A(n);
  bool poss = false;
  for (auto &a : A) {
    cin>>a;
    if (a==100) poss=true;
  }
  cout<<(poss?"Yes":"No")<<"\n";
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