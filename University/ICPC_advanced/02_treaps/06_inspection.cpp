/**
 *    author:  gemtec
 *    created: 04.12.2025 14:04:07
 *    problem: https://domjudge.iti.kit.edu/main/team/problems/51/statement
**/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

const int K =6;

struct Treap {
    struct Node {
        int val, prio;
        int sz;
        array<int, K> cnt;
        ll inc;
        Node *l, *r;
        Node(int v, int p) : val(v), prio(p), sz(1), cnt{0}, inc(0), l(nullptr), r(nullptr) {cnt[val] = 1;}
    };

    vector<Node> pool;
    int ptr = 0;

    Treap(int max_nodes) {
        pool.reserve(max_nodes);
    }

    Node* make_node(int v, int p) {
        pool.emplace_back(v, p);
        return &pool.back();
    }

    struct Agg {
        bool empty;
        array<int, K> cnt;
        ll inc;
    };

    static Agg aggregate(Node* t) {
        if (!t) return {true, {}, 0};
        return {false, t->cnt, t->inc};
    }

    static Agg combine(const Agg &a, const Agg &b) {
        if (a.empty) return b;
        if (b.empty) return a;
        Agg res;
        res.empty=false;

        res.inc=a.inc+b.inc;
        for (int i=0; i<K; i++) {
            for (int j=i+1; j<K; j++) {
                res.inc += 1LL * a.cnt[i] * b.cnt[j];
            }
        }
        for (int i=0; i<K; i++) res.cnt[i] = a.cnt[i] + b.cnt[i];
        return res;
    }

    Node* root = nullptr;
    mt19937 rng{(uint32_t)chrono::steady_clock::now().time_since_epoch().count()};

    static int sz(Node* t) { return t ? t->sz : 0; }

    static void pull(Node* t) {
        if (t) { 
            t->sz = 1 + sz(t->l) + sz(t->r);

            Agg L = aggregate(t->l);
            Agg R = aggregate(t->r);
            Agg M;
            M.empty = false;
            M.cnt.fill(0);
            M.cnt[t->val] = 1;
            M.inc = 0;
            Agg sol = combine(combine(L,M),R);

            t->cnt = sol.cnt;
            t->inc = sol.inc;
        }
    }

    static pair<Node*, Node*> split(Node* v, int k) {
        if (!v) return {nullptr, nullptr};
        if (sz(v->l) >= k) { // first k elements
            auto [a, b] = split(v->l, k);
            v->l = b;
            pull(v);
            return {a, v};
        } else { // remaining elemnts
            auto [a, b] = split(v->r, k - sz(v->l) - 1);
            v->r = a;
            pull(v);
            return {v, b};
        }
    }

    static Node* merge(Node* a, Node* b) { // concatenate b onto a
        if (!a) return b;
        if (!b) return a;
        if (a->prio < b->prio) { // min-heap on prio
            a->r = merge(a->r, b);
            pull(a);
            return a;
        } else {
            b->l = merge(a, b->l);
            pull(b);
            return b;
        }
    }

    void insert_at(int pos, int v) {
        auto [a, b] = split(root, pos);
        root = merge(merge(a, make_node(v, (int)rng())), b);
    }

    void push_back(int v) { insert_at(sz(root), v); }

    ll count_and_pushback(int l, int r) {
        l--; r--;
        if (l==r) return 0;
        debug(l,r);
        auto [a, rest] = split(root,l);
        // debug(a? a->first:-1,a? a->last:-1,rest? rest->first:-1,rest? rest->last : -1);
        auto [m, b] = split(rest, r-l+1);
        // debug(m? m->first:-1,m? m->last:-1,b? b->first:-1,b? b->last : -1);
        ll sol = m? m->inc: 0;
        if (sol!=0) root = merge(merge(a,b),m);
        else root=merge(merge(a,m),b);
        return sol;
    }

    void output(Node* t) {
        if (!t) return;
        output(t->l);
        cout<<t->val<<" ";
        output(t->r);
    }

    void print() {
        output(root);
        cout<<endl;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,q;cin>>n>>q;
    Treap t(n+q+K);
    for (int i=0;i<n;i++) {
        int rank;cin>>rank;
        t.push_back(rank);
    }

    for (int i=0;i<q;i++) {
        int l,r; cin>>l>>r;
        cout<<t.count_and_pushback(l,r)<<endl;
    }
    t.print();

    return 0;
}