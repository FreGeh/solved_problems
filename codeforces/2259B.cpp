/**
 *      author:  gemtec
 *      created: 05.09.2026 16:54:18
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
  int n;cin>>n;
  vector<int> A(n);
  ll odd=0;
  ll mod2even=0;
  ll mod2odd=0;
  for (int i=0;i<n;i++) {
    int a;cin>>a;
    if ((a&1)==1) { //odd
      odd++;
    } else {
      if (((a/2)&1)==0) {
        mod2even++;
      } else {
        mod2odd++;
      }
    }
  }
  // cout<<"odd: "<<odd<<endl;
  cout<<max(odd,max(mod2even,mod2odd))<<endl;
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