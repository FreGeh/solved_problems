/**
 *      author:  gemtec
 *      created: 18.12.2025 19:53:29
 *      link: https://domjudge.iti.kit.edu/main/team/problems/61/statement
 *      idea: use dsu to build max kruskal tree and always take min edge as ans
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

struct DSU {
// Index 0 unused, 1 = Root, 1 to len-1 = Internal, len to 2*len-1 = Leaves
    vector<int> parent,rank;
    DSU() {}
    DSU(int n) { init(n); }

    void init(int n) {
        parent.resize(n);
        rank.assign(n, 0);
    }

    void make_set(int v) {
        parent[v] = v;
        rank[v] = 0;
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        }
    }

    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

};

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight > other.weight;
    }
};

static const int INF = 2000000007;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,c,q;cin>>n>>c>>q;
    vector<Edge> edges;
    for (int i=0;i<c;i++) {
        int start,end,resistance; cin>>start>>end>>resistance;
        edges.push_back({start, end, resistance});
    }
    sort(edges.begin(), edges.end());

    DSU dsu;
    dsu.init(n);
    for (int i = 0; i < n; i++) dsu.make_set(i);

    vector<vector<pair<int,int>>> adj(n);
    int pick=0;
    for (auto &e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.unite(e.u, e.v);
            adj[e.u].push_back({e.v, e.weight});
            adj[e.v].push_back({e.u, e.weight});
            pick++;
            if (pick == n-1) break;
        }
    }
    // build binary resistance on maximum kruskal tree 

    int log_n = 1;
    while ((1 << log_n) <= n) log_n++;

    vector<vector<int>> up(n, vector<int>(log_n, 0));
    vector<vector<int>> mn(n, vector<int>(log_n, INF));
    vector<int> depth(n, 0);
    vector<int> parent(n, -1);
    parent[0]=0;
    up[0][0]=0;
    mn[0][0]=INF;
    depth[0]=0;
    stack<int> st;
    st.push(0);

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (auto [v, w] : adj[u]) {
            if (v==parent[u]) continue;
            parent[v]=u;
            depth[v]=depth[u]+1;
            up[v][0]=u;
            mn[v][0]=w;
            st.push(v);
        }
    }
    for (int j=1; j<log_n; j++) {
        for (int v=0; v<n; v++) {
            int mid = up[v][j-1];
            up[v][j] = up[mid][j-1];
            mn[v][j] = min(mn[v][j-1], mn[mid][j-1]);
        }
    }
    auto highest_safety = [&](int a, int b) -> int {
        int res=INF;
        if (depth[a]<depth[b]) swap(a,b);
        int dif=depth[a]-depth[b];
        for (int j=log_n-1; j>=0;j--) {
            if (1 & (dif>>j)) {
                res=min(res,mn[a][j]);
                a=up[a][j];
            }
        }
        if (a==b) return res;
        //ansonsten noch
        for (int j=log_n-1; j>=0;j--) {
            if (up[a][j]!=up[b][j]) {
                res=min(res,mn[a][j]);
                res=min(res,mn[b][j]);
                a=up[a][j];
                b=up[b][j];
            }
        }
        res=min(res,mn[a][0]);
        res=min(res,mn[b][0]);
        return res;
    };

    ll cur=0;
    for (int i=0;i<q;i++) {
        int a,b;cin>>a>>b;
        int u=(a+cur)%n;
        int v=(b+cur)%n;
        int ans=highest_safety(u,v);
        cur=ans;
        cout<<ans<<endl;
    }

    return 0;
}