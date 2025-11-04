#include "bits/stdc++.h"
using namespace std;
#define ll long long

struct edge
{
    int64_t from, to;
    int64_t flow, cap;
    edge *twin;
};

vector<vector<edge *>> adj;

void add_edge(int64_t v, int64_t w, int64_t cap)
{
    edge *e1 = new edge{v, w, 0, cap, nullptr};
    edge *e2 = new edge{w, v, 0, 0, nullptr};
    e1->twin = e2;
    e2->twin = e1;
    adj[v].push_back(e1);
    adj[w].push_back(e2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    adj.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add_edge(a,b,c);
        add_edge(b,a,c);
    }

    int64_t flow = 0;
    int64_t s=1;
    int64_t t=2;
    while (true)
    {
        vector<edge *> inc(n+1, nullptr);
        queue<int64_t> q{{s}};
        while (!q.empty())
        {
            auto v = q.front();
            q.pop();
            for (auto e : adj[v])
                if (!inc[e -> to] && e -> flow<e -> cap)
                {
                    q.push(e -> to);
                    inc[e -> to] = e;
                }
        }
        if (!inc[t]) break;
        int64_t aug = 1e9;
        for (int64_t v = t; v != s; v = inc[v] -> from)
            aug = min(aug, inc[v] -> cap - inc[v] -> flow);
        flow += aug;
        for (int64_t v = t; v != s; v = inc[v] -> from)
        {
            inc[v] -> flow += aug;
            inc[v] -> twin -> flow -= aug;
        }
    }
    cout << flow << "\n";

    return 0;
}
