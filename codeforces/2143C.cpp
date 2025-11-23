#include "bits/stdc++.h"
using namespace std;
#define ll long long

// Conditional compilation
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) do { } while(0)
#endif

void solve() {
    int n;cin>>n;
    vector<vector<int>> adj(n+1);
    vector<int> in_degrees(n+1);
    for (int i=0;i<n-1;i++) {
        int u,v,x,y; cin>>u>>v>>x>>y;
        if (x>=y) {
            adj[u].push_back(v);
            in_degrees[v]++;
        } else {
            adj[v].push_back(u);
            in_degrees[u]++;
        }
    }

    queue<int> q;
    for (int i=1;i<n+1;i++) {
        if (in_degrees[i]==0) {
            q.push(i);
        }
    }
    vector<int> order;
    while (!q.empty()) {
        int parent = q.front();
        order.push_back(parent);
        q.pop();

        for (auto kid : adj[parent]) {
            if (--in_degrees[kid] == 0) q.push(kid);
        }
    }
    vector<int> res(n+1);
    for (int i=0;i<n;i++) {
        res[order[i]]=n-i;
    }
    for (int i=1;i<n+1;i++) {
        cout<<res[i]<<" ";
    }
    cout<<"\n";
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
