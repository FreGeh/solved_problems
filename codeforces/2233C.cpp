/**
 *      author:  gemtec
 *      created: 09.06.2026 17:39:00
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
  int n,k;cin>>n>>k;
  ll sum=0, mini=0, c=-1;
  string s;
  cin>>s;
  for (int i=0;i<n;i++) {
    if (s[i]=='(') {
      sum++;
    } else {
      sum--;
    }
    if (sum<mini) {
      mini=sum;
      c=i;
    }
  }
  vector<int> sol;
  int removed=0;  
  for (int i=0;i<n;i++) {
    if (((s[i]=='(' && i<=c) || (s[i]==')' && i>c)) && removed<k) { 
      sol.push_back(1); 
      removed++;
    }
    else sol.push_back(0);
  }
  for (auto i : sol) {
    cout<<i;
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