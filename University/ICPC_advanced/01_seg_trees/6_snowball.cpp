#include "bits/stdc++.h"
using namespace std;
#define ll long long

struct Node {
    ll first_el, last_el;
    bool is_decr, is_incr, is_empty;

    Node() : first_el(0), last_el(0), is_decr(true), is_incr(true), is_empty(true) {}

    Node(ll val) : first_el(val), last_el(val), is_decr(true), is_incr(true), is_empty(false) {}
};

Node merge(Node &l, Node &r) {
    if (l.is_empty) return r;
    if (r.is_empty) return l;

    Node res;
    res.first_el=l.first_el;
    res.last_el=r.last_el;
    res.is_empty=false;
    res.is_decr=(l.is_decr && r.is_decr) && (l.last_el>r.first_el);
    res.is_incr=(l.is_incr && r.is_incr) && (l.last_el<r.first_el);

    return res;
}

struct SegTree {
    int n;
    vector<Node> tree;

    SegTree(const vector<ll>& A) {
        n = A.size();
        tree.resize(2*n);
        for (int i=0; i<n; i++) 
            tree[i+n] = Node(A[i]);
        for (int i=n-1; i>0; i--)
            tree[i] = merge(tree[2*i], tree[2*i+1]);
    }

    void update(int pos, ll val) {
        pos+=n;
        tree[pos] = Node(val);
        for (pos /= 2; pos >= 1; pos /= 2) {
            tree[pos] = merge(tree[2*pos], tree[2*pos+1]);
        }
    }

    Node query(int l, int r) {
        r++;
        Node left, right;
        
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l&1) {
                left = merge(left, tree[l]);
                l++;
            }
            if (r&1) {
                r--;
                right = merge(tree[r], right);
            }
        }
        return merge(left, right);
    }

    bool increasing(int q_l, int q_r) {
        return query(q_l, q_r).is_incr;
    }

    bool decreasing(int q_l, int q_r) {
        return query(q_l, q_r).is_decr;
    }
};


void solve() {
    int n,q;cin>>n>>q;
    vector<ll> heights(n);
    for (auto &h : heights) {
        cin>>h;
    }
    SegTree seg(heights);
    for (int i=0;i<q;i++) {
        char type; cin>>type;
        if (type == 'B') {
            int index_1,index_2;cin>>index_1>>index_2;
            bool res=false;
            index_1--; index_2--; // my segtree is zero-indexed
            if (index_1 < index_2) {
                res=seg.decreasing(index_1, index_2);
            } else {
                res=seg.increasing(index_2, index_1);
            }
            cout<<(res?"YES":"NO")<<"\n";
        } else {
            int index;
            ll height;
            cin>>index>>height;
            index--;
            seg.update(index, height);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    solve();
    return 0;
}
