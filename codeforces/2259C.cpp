/**
 *      author:  gemtec
 *      created: 05.09.2026 17:04:31
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
  int first=-1,last=-1, lastone=-1;
  bool one=false;
  for (int i=0;i<n;i++) {
    int a;cin>>a;
    if (a==1) { 
      one=true; 
      lastone=i;
    }
    if (a==-1) {
      a=0;
      last=i;
      if (first==-1) {
        if (!one) {
          a=1;
          one=true;
        }
        first=i; 
      }
    }
    A[i]=a;
  }
  if (lastone<last) {
    A[last]=1;
  }
  for (auto &a: A) {
    cout<<a<<" ";
  }
  cout<<endl;
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