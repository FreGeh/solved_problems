/**
 *      author:  gemtec
 *      created: 17.01.2026 13:29:03
 *      link:
 *      idea:
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,m,l,s,t;
    cin>>n>>m>>l>>s>>t;
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i=0; i<m; i++) {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
    }
    vector<bool> reached(n+1, false);
    auto dfs = [&](auto &&self, int u, ll cur, ll edges) -> void {
        if (edges<l) {
            for (auto [v,c] : adj[u]) {
                if (cur+c<=t) {
                    // cout<<"nodes: "<<u<<" "<<v<<" via "<<c<<" equals "<<cur+c<<endl;
                    if (cur+c>=s && edges+1==l) { 
                        reached[v]=true; 
                        // cout<<"reached"<<endl;
                    }
                    self(self, v, cur+c, edges+1);
                }
            }
        }
    };
    dfs(dfs, 1, 0, 0);
    for (int i=1; i<=n; i++) {
        if (reached[i]) cout<<i<<" ";
    }

    return 0;
}