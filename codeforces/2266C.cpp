/**
 *      author:  gemtec
 *      created: 21.09.2026 16:50:03
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
  string s; cin>>s;
  ll count=0;
  
  if (s[0]=='1') { //ducked
    for (char c:s) if (c=='0') count++;
  } else {
    ll found=0;
    for (char c:s) {
      if (c=='1') found++;
      else {
        count=min(count+1,found);
      }
    }
  }
  cout << count<<endl;
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