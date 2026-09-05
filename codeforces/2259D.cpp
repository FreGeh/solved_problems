/**
 *      author:  gemtec
 *      created: 05.09.2026 17:21:51
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
  vector<vector<int>> A(n+1);
  int zeroes=0;
  for (int i=0;i<n;i++) {
    int a;
    cin>>a;
    if (a==0) zeroes++;
    if (a<=n) A[a].push_back(i);
  }

  if (zeroes==1) { // notposs
    cout<<"NO"<<endl;
    return;
  }
  cout<<"YES"<<endl;

  string res(n, 'A');
  if (zeroes==0) {
    cout<<res<<endl;
    return;
  }

  //otherwisae we have to do shit

  int mex=0;
  while (mex<=n && A[mex].size()>=2) mex++;

  for (int i=0; i<mex;i++) {
    res[A[i][0]] = 'B';
    res[A[i][1]] = 'C';
  }

  for (int &a : A[0]) {
    if (res[a]=='A') res[a]='B';
  }
  cout<<res<<endl;
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