/**
 *    author:  gemtec
 *    created: 05.12.2025 19:42:53
 *    problem: https://domjudge.iti.kit.edu/main/team/problems/63/statement
**/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

// use like this: SparseTable<int, function<int(int,int)>> st(a,[](int x, int y){ return ...(x, y); });
template <class T, class F>
struct SparseTable {
    int n = 0;
    vector<vector<T>> M;
    F function; // (only idempotent functions, like min, max, gcd, and, or)

    SparseTable(const vector<T>& a, F f) : n((int)a.size()), function(f) {
        assert(n > 0);
        int K = bit_width((unsigned)n); // floor(log2(n)) + 1
        // int K = 32 - __builtin_clz((unsigned)n);
        M.resize(K);
        M[0] = a;

        for (int k = 1; k < K; ++k) {
            int len = 1 << k;
            M[k].resize(n-len+1);
            for (int i = 0; i+len <= n; ++i) {
                M[k][i] = function(M[k-1][i], M[k-1][i+(len >> 1)]);
            }
        }
    }

    // inclusive range [l, r]
    T query(int l, int r) const {
        assert(0 <= l && l <= r && r < n);
        int len = r-l+1;
        int k = bit_width((unsigned)len) - 1; // floor(log2(len))
        // int k = 31 - __builtin_clz((unsigned)len);
        return function(M[k][l], M[k][r-(1 << k)+1]);
    }
};

vector<int> depth, first;
vector<int> euler, euler_depth;

void dfs(vector<vector<int>> &g, int v, int p, int d) {
	depth[v] = d;
	first[v] = euler.size();
	euler.push_back(v);
    euler_depth.push_back(d);
	for (auto nei : g[v]) {
		if (nei != p) {
			dfs(g, nei, v, d+1);
			euler.push_back(v);
            euler_depth.push_back(d);
		}
	}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,q;cin>>n>>q;
    vector<vector<int>> g(n);
    for (int i=0;i<n-1;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    depth.assign(n,0);
    first.assign(n,-1);

    dfs(g, 0, -1, 0);
    int euler_size=euler.size();
    vector<pair<int,int>> euler_comb(euler_size);
    for (int i=0; i<euler_size;i++) {
        euler_comb[i]={euler_depth[i],euler[i]};
    }

    SparseTable<pair<int,int>, function<pair<int,int>(pair<int,int>,pair<int,int>)>> st(
        euler_comb,
        [](const pair<int,int> &x, const pair<int,int> &y){ return min(x, y); });

    for (int i=0;i<q;i++) {
        int u,v;cin>>u>>v; u--;v--;
        int l = first[u], r = first[v];
        pair<int,int> res = st.query(min(l,r),max(l,r));
        cout<<depth[u]-depth[res.second] + depth[v]-depth[res.second]<<"\n";
    }

    return 0;
}