#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) do { } while(0)
#endif

void visit(int v, vector<bool> &visited, vector<vector<int>> &adjlist) {
    visited[v] = true;
    for (int w : adjlist[v]) {
        if (!visited[w]) {
            visit(w, visited, adjlist);
        }
    }
}

void solve() {
    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n+1, vector<int>());
    for (int i=0;i<m;i++) {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int s=1;
    vector<bool> visited(n+1, false);
    vector<pair<int,int>> res;
    visit(s, visited, adj);
    for (int w=1;w<n+1;w++) {
        if (!visited[w]) {
            visit(w, visited, adj);
            res.push_back({1,w});
        }
    }

    int outputsize=res.size();
    cout<<outputsize<<endl;
    for (auto &[a,b] : res) {
        cout<<a<<" "<<b<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    solve();
    return 0;
}
