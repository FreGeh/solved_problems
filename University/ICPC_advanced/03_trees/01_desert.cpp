/**
 *      author:  gemtec
 *      created: 18.12.2025 14:01:52
 *      link: https://domjudge.iti.kit.edu/main/team/problems/60/statement
 *      idea: does the added edge alter the graph so two simple cycles share more than 1 node aka graph is not cactus anymore
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

bool two_cycle(vector<vector<int>> &adj) {

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,q;cin>>n>>q;
    vector<vector<int>> adj(n+1);
    for (int i=0;i<q;i++) {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (i>n+1) {
            if (!two_cycle(adj)) { 
                cout<<"YES\n"; 
            }
            else { 
                cout<<"NO\n";
            }
        } else {
            cout<<"YES\n";
        }
    }

    return 0;
}