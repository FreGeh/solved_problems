/**
 *    author:  gemtec
 *    created: 16.12.2025 13:02:33
 *    problem: https://domjudge.iti.kit.edu/main/team/problems/66/statement
 *    idea: minimize max component sum by removing up to k edges
**/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,k; cin>>n>>k;
    vector<int> pop(n);
    ll biggest=0;
    for (auto &p : pop) {
        cin>>p;
        biggest+=p;
    }
    vector<vector<int>> adj(n);
    for (int i=0;i<n-1;i++) {
        int a,b;cin>>a>>b; a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<pair<int,int>> list;

    auto possible = [&](ll infested, int max_cuts) -> bool {
        if (*max_element(pop.begin(), pop.end()) > infested) return false;

        int cuts=0;
        queue<int> q;
        list.clear();

        auto dfs = [&](auto&& self, int u, int p) -> ll {
            ll cur=pop[u];
            vector<pair<ll,int>> child;
            for (auto v : adj[u]) {
                if (v!=p) { 
                    ll s=self(self, v,u);
                    child.push_back({s,v});
                }
            }
            sort(child.begin(), child.end());

            for (auto [s,v]:child) {
                if (cur+s<=infested) {
                    cur+=s;
                } else {
                    cuts++;
                    list.push_back({u,v});
                }
            }
            return cur;
        };  
        dfs(dfs, 0,-1);
        return (cuts<=max_cuts);
    };

    // binary search, val x
    ll l,r; l=0; r=biggest;
    ll sol=-1;
    vector<pair<int,int>> sol_list;
    while (l<=r) {
        ll m=l+(r-l)/2;
        debug(m,k);
        if (possible(m, k)) {
            sol=m;
            sol_list=list;
            r=m-1;
        } else {
            l=m+1;
        }
    }
    cout<<sol_list.size()<<" "<<sol<<endl;
    for (auto s : sol_list) {
        cout<<s.first+1<<" "<<s.second+1<<endl;
    }
    // starting from leaves addup subtree sum
    // if exceeds x, start new component and remove that edge, 
    // if we need more than k edges, move binary search up

    return 0;
}