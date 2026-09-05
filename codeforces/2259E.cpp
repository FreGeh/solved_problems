/**
 *      author:  gemtec
 *      created: 05.09.2026 17:42:02
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

const int INF = 1e9;

void solve() {
  int n; cin>>n;
  vector<int> map(n), none_dif(n+1);
  for (int i=0;i<n;i++) {
    int a; cin>>a;
    map[i]=a; 
    
    if (a>0) {
      int l=max(0,i-a+1);
      int r=min(i+a-1,n-1);
      none_dif[l]++;
      none_dif[r+1]--;
    }
  }
  string treasure(n, '0');

  int cur=0;
  for (int i=0;i<n;i++) {
    cur+=none_dif[i];
    if (cur==0) treasure[i]='1';
  }

  //check if real
  vector<int> distance(n, INF);
  int last=-INF;
  for (int i=0;i<n;i++) {
    if (treasure[i]=='1') last=i;
    distance[i]=min(distance[i],i-last);
  }

  last=INF;
  for (int i=n-1;i>=0;i--) {
    if (treasure[i]=='1') last=i;
    distance[i]=min(distance[i],last-i);
  }

  for (int i=0;i<n;i++) {
    if (distance[i] != map[i] && map[i]!=-1) {
      cout<<-1<<endl;
      return;
    }
  }

  cout<<treasure<<endl;
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