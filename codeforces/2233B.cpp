/**
 *      author:  gemtec
 *      created: 09.06.2026 16:44:20
 *      link:
 *      idea:
 *      learning:
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long
using pii = pair<int,int>;

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

void solve() {
  int n;cin>>n;
  queue<int> q;
  
  for (int i=1;i<=n;i++) q.push(i);
  for (int i=1;i<=n;i++) q.push(i);
  q.push(n);
  for (int i=1;i<n;i++) q.push(i);
  for (int i=1;i<=n;i++) q.push(i);

  while (!q.empty()) {
    cout<<q.front()<<" ";
    q.pop();
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