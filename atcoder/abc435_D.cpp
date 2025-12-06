/**
 *    author:  gemtec
 *    created: 06.12.2025 13:41:43
 *    problem:
**/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

vector<vector<int>> adj;
vector<int> white;

void activate(int u) {
    white[u]=0;
    for (int v : adj[u]) {
        if (white[v]) activate(v);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,m;cin>>n>>m;
    adj.assign(n+1, vector<int>());
    white.assign(n+1, 1);
    for (int i=0;i<m;i++) {
        int x,y;cin>>x>>y;
        adj[y].push_back(x);
    }

    int q; cin>>q;
    for (int i=0;i<q;i++) {
        int typ, v; cin>>typ>>v;
        if (typ==1) {
            if (white[v]) activate(v);
        } else {
            cout << (!white[v]?"Yes":"No") << endl;
        }
    }

    return 0;
}