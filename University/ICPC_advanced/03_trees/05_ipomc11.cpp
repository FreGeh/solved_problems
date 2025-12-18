/**
 *    author:  gemtec
 *    created: 05.12.2025 20:27:25
 *    problem: https://domjudge.iti.kit.edu/main/team/problems/64/statement
 *    focus: for each control give any node reachable in the amount of c steps
 *    idea: seems like binary lifting so we do jumps and check if there is a valid distance equal to the cheese they have from that node
**/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

void dfs(int u, vector<vector<int>> &adj, vector<vector<int>> &ancestor, vector<int> &depth, int parent) {
    ancestor[u][0] = parent;
    for (int v : adj[u]) {
        if (v == parent) continue;
        depth[v] = depth[u] + 1;
        dfs(v, adj, ancestor, depth, u);
    }
}

int lift(vector<vector<int>> &ancestor, int u, int k, int log_n) {
    for (int i = log_n-1; i >= 0; i--) {
        if (1 & (k >> i)) { // if i-th bit of k == 1
            u = ancestor[u][i]; //jump up
            if (u==-1) return -1;
        }
    }
    return u;
}

int lca(vector<vector<int>> &ancestor, vector<int> &depth, int a, int b, int log_n) {
    if (depth[a]<depth[b]) swap(a, b); // always take deeper node

    a = lift(ancestor, a, depth[a]-depth[b], log_n); // lift deeper node up
    if (a == b) return a;

    for (int i=log_n-1; i>=0; i--) {
        if (ancestor[a][i]!=ancestor[b][i]) { // same parent is lca
            a=ancestor[a][i];
            b=ancestor[b][i];
        }
    }
    return ancestor[a][0];
}

int bfs_far(int start, const vector<vector<int>> &adj, vector<int> &dist) {
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }

    int far = start;
    for (int i=1; i<(int)dist.size(); i++) {
        if (dist[i]>dist[far]) far=i;
    }
    return far;
}

int kth_on_path(vector<vector<int>> &ancestor, vector<int> &depth, int u, int v, int k, int log_n) {
    int w = lca(ancestor, depth, u, v, log_n);
    int du = depth[u] - depth[w];
    int dv = depth[v] - depth[w];
    if (k <= du) return lift(ancestor, u, k, log_n); // go up from u
    int need_up_from_v = du + dv - k; // go up from v
    return lift(ancestor, v, need_up_from_v, log_n);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,q;cin>>n>>q;
    int log_n=log2(n)+1;
    vector<vector<int>> adj(n+1), ancestor(n+1, vector<int>(log_n,-1));
    vector<int> depth(n+1,0);
    for (int i=0;i<n-1;i++) {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // preprocessing ancestors
    depth[1]=0;

    dfs(1, adj, ancestor, depth, -1);
    for (int j=1; j<log_n; j++) {
        for (int i=1; i<=n; i++) {
            int mid = ancestor[i][j-1];
            if (mid!=-1) ancestor[i][j] = ancestor[mid][j-1];
        }
    }

    // queries
    vector<int> dist1(n+1,-1), distA(n+1,-1), distB(n+1,-1);
    int A = bfs_far(1, adj, dist1);
    int B = bfs_far(A, adj, distA);
    bfs_far(B, adj, distB);
    for (int i=0;i<q;i++) {
        int s,c;cin>>s>>c;
        debug(s,c);
        int sol=-1;
        if (distA[s]>=c) sol= kth_on_path(ancestor, depth, s, A, c, log_n);
        else if (distB[s]>=c) sol= kth_on_path(ancestor, depth, s, B, c, log_n);
        
        cout<<sol<<"\n";
    }

    return 0;
}