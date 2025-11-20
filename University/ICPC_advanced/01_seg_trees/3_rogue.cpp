#include "bits/stdc++.h"
using namespace std;
#define ll long long

struct SumSegmentTree {
    int n;
    vector<ll> tree;

    SumSegmentTree(int n_) : n(n_), tree(4 * n_, 0) {}

    void update(int v, int tl, int tr, int pos, ll val) {
        if (tl == tr) {
            tree[v] += val;
        } else {
            int tm = tl + (tr - tl) / 2;
            if (pos <= tm) {
                update(v * 2, tl, tm, pos, val);
            } else {
                update(v * 2 + 1, tm + 1, tr, pos, val);
            }
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    void add(int pos, ll val) {
        update(1, 0, n-1, pos, val);
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return tree[v];
        }
        int tm = tl + (tr-tl) / 2;
        ll left_sum = query(v * 2, tl, tm, l, min(r, tm));
        ll right_sum = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return left_sum + right_sum;
    }
};

struct Monster {
    ll s, c;
    int id;

    bool operator<(const Monster &x) const {
        return s < x.s;
    }
};

struct Query {
    int l, r;
    ll s;
    int id;

    bool operator<(const Query &x) const {
        return s < x.s;
    }
};


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin>>n;
    vector<Monster> monsters(n);
    for (int i = 0; i < n; i++) {
        cin>>monsters[i].s>>monsters[i].c;
        monsters[i].id = i;
    }

    int q;cin>>q;
    vector<Query> queries(q);
    for (int i=0; i<q; i++) {
        cin>>queries[i].l>>queries[i].r>>queries[i].s;
        queries[i].l--; queries[i].r--;
        queries[i].id=i;
    }
 
    sort(monsters.begin(), monsters.end());
    sort(queries.begin(), queries.end());

    vector<ll> answers(q);
    SumSegmentTree seg(n);
    int cur_id=0;
    for (int i = 0; i < q; i++) {
        while (cur_id < n && monsters[cur_id].s < queries[i].s) {
            seg.add(monsters[cur_id].id, monsters[cur_id].c);
            cur_id++;
        }

        answers[queries[i].id] = seg.query(1, 0, n-1, queries[i].l, queries[i].r);
    }

    for (int i=0;i<q;i++) {
        cout<<answers[i]<<"\n";
    }
    

    return 0;
}
