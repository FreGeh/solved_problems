/**
 *    author:  gemtec
 *    created: 04.12.2025 17:26:10
 *    problem:
**/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

struct Treap {
    struct Node {
        int key, prio;
        int sz;
        ll sum;
        int mn,mx;
        Node *l, *r;
        Node(int k, int p) : key(k), prio(p), sz(1), sum(k), mn(k), mx(k), l(nullptr), r(nullptr) {}
    };
    Node* root = nullptr;
    mt19937 rng{(uint32_t)chrono::steady_clock::now().time_since_epoch().count()};

    static int sz(Node* t) { return t ? t->sz : 0; }
    static ll sum(Node* t) { return t ? t->sum : 0LL; }
    static int mn(Node* t) { return t ? t->mn : INT_MAX; }
    static int mx(Node* t) { return t ? t->mx : INT_MIN; }

    static void pull(Node* t) { 
        if (t) {
            t->sz = 1 + sz(t->l) + sz(t->r);
            t->sum = sum(t->l) + sum(t->r) + (ll)t->key;
            t->mn = min(min(mn(t->l),mn(t->r)),t->key);
            t->mx = max(max(mx(t->l),mx(t->r)),t->key);
        }
    }

    static pair<Node*, Node*> split(Node* v, int x) { // split into (< x) and (>= x)
        if (!v) return {nullptr, nullptr};
        if (v->key < x) {
            auto [rl, rr] = split(v->r, x);
            v->r = rl;
            pull(v);
            return {v, rr};
        } else {
            auto [sl, sr] = split(v->l, x);
            v->l = sr;
            pull(v);
            return {sl, v};
        }
    }

    static Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;
        if (a->prio < b->prio) {
            a->r = merge(a->r, b);
            pull(a);
            return a;
        } else {
            b->l = merge(a, b->l);
            pull(b);
            return b;
        }
    }

    void insert(int x) {
        auto [a, b] = split(root, x);
        root = merge(merge(a, new Node(x, rng())), b);
    }

    int find_sum(ll target) const {
        Node* cur = root;
        while (cur) {
            ll leftSum = sum(cur->l);
            if (target < leftSum) {
                cur = cur->l;
            } else if (target < leftSum + (ll)cur->key) {
                return cur->key;
            } else {
                target -= leftSum+ (ll)cur->key;
                cur = cur->r;
            }
        }
        return -1;
    }

    static Node* erase(Node* t, int x){
        if(!t) return nullptr;
        if(x < t->key){
            t->l = erase(t->l, x); 
            pull(t); 
            return t;
        }else if(x > t->key){
            t->r = erase(t->r, x); 
            pull(t); 
            return t;
        }else{
            Node* res = merge(t->l, t->r);
            t->l = t->r = nullptr;
            delete t;
            return res;
        }
    }
    void erase(int x){ root = erase(root, x); }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;cin>>n;
    vector<ll> B(n+1);
    for (int i=1;i<=n;i++) { 
        cin >> B[i]; 
    }
    Treap t;
    for (int i=1;i<=n;i++) {
        t.insert(i);
    }

    vector<int> ans(n+1);
    for (int i=n;i>=1;i--) {
        int val=t.find_sum(B[i]);
        ans[i]=val;
        t.erase(val);
    }
    
    for (int i=1; i<=n; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;


    return 0;
}