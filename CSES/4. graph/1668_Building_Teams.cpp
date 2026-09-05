/**
 *      author:  gemtec
 *      created: 08.06.2026 15:14:40
 *      link:
 *      idea:
 *      learning:
*/

// clean BFS implementation
#include "bits/stdc++.h"
using namespace std;

vector<int> team;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int n, m; cin>>n>>m;
  team.assign(n,0);
  vector<vector<int>> adj(n);
  for (int i=0;i<m;i++) {
    int a,b;
    cin>>a>>b;
    a--;b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  bool poss = true;
  for (int i=0;i<n && poss;i++) {
    if (team[i]!=0) continue;

    queue<int> q;
    q.push(i);
    team[i]=1;

    while (!q.empty() && poss) {
      int cur = q.front();
      q.pop();
      for (auto &u : adj[cur]) {
        if (team[u]==0) {
          team[u]=3-team[cur];
          q.push(u);
        }
        else if (team[u]==team[cur]) {
          poss = false;
          break;
        }
      }
    }
  }
  
  if (poss) {
    for (int i=0;i<n;i++) {
      cout<<team[i]<<" ";
    }
  } else {
    cout<<"IMPOSSIBLE";
  }

  return 0;
}