/**
 *      author:  gemtec
 *      created: 08.06.2026 18:40:40
 *      link: https://codeforces.com/problemset/problem/1674/D
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
  vector<int> A(n);
  for (int i=0;i<n;i++) {
    cin>>A[i];
  }

  bool poss=true;
  if (n<=2) { 
    poss =true;
  }
  else {
    if (n%2 == 1) {
      if (A[0] > A[1] || A[0] > A[2]) poss = false;
    }
    for (int i=n%2;i<n-3 && poss;i+=2) {
      if (max(A[i], A[i+1])>min(A[i+2], A[i+3])) {
        poss =false;
        break;
      }
    }
  }

  if (poss) {
    cout<<"YES"<<endl;
  } else {
    cout<<"NO"<<endl;
  }
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