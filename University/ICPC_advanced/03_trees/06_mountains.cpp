/**
 *    author:  gemtec
 *    created: 13.12.2025 18:59:39
 *    problem: https://domjudge.iti.kit.edu/main/team/problems/65/statement
 *    goal: number of sequence of mountain peaks with distinct peaks, starting and ending different where starting peak >= all others
**/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

#include "bits/stdc++.h"
using namespace std;
#define ll long long

struct DSU {
// Index 0 unused, 1 = Root, 1 to len-1 = Internal, len to 2*len-1 = Leaves
    vector<int> parent,rank;
    DSU() {}
    DSU(int n) { init(n); }

    void init(int n) {
        parent.resize(n);
        rank.assign(n, 1);
    }

    void make_set(int v) {
        parent[v] = v;
        rank[v] = 1;
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            rank[a] += rank[b];
        }
    }

    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    int get_size(int v) {
        return rank[find(v)];
    }
};


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;cin>>n;
    vector<int> h(n);
    for (int i=0;i<n;i++) {
        cin>>h[i];
    }
    vector<vector<int>> adj(n);
    for (int i=0;i<n-1;i++) {
        int a,b;cin>>a>>b; a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<pair<int,int>> nodes(n);
    for (int i=0; i<n; i++) { 
        nodes[i]= {h[i], i}; 
    }

    sort(nodes.begin(), nodes.end());

    vector<bool> active(n, false);

    ll sol=0;

    DSU uf(n);

    for (int i=0;i<n;) {
        int h =nodes[i].first;
        int counter=i;
        while (counter<n && nodes[counter].first == h) counter++;
        for (int j=i;j<counter;j++) {
            int v = nodes[j].second;
            active[v]=true;
            uf.make_set(v);
        }
        for (int j=i;j<counter;j++) {
            int v = nodes[j].second;
            for (auto u : adj[v]) {
                if (active[u]) uf.unite(v, u);
            }
        }
        for (int j=i;j<counter;j++) {
            int v = nodes[j].second;
            sol+=uf.get_size(v)-1;
        }
        i=counter;
    }

    cout<<sol<<endl;

    return 0;
}