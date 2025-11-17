#include "bits/stdc++.h"
using namespace std;
#define ll long long

vector<ll> range_coords;

struct SegTree_Lazy {
    ll n;
    vector<ll> seg, lazy_sum;

    SegTree_Lazy() : n(0) {}
    explicit SegTree_Lazy(int n_) { 
        init(n_); 
    }

    void init(int n_) { 
        n=n_; 
        seg.assign(4*n,0); 
        lazy_sum.assign(4*n,0); 
    }

    void add(int l,int r,ll v) { 
        update(1,0,n-1,l,r,v); 
    }

    ll sum(int l,int r) { 
        return query(1,0,n-1,l,r); 
    }

private:
    inline void apply(int v,int l,int r,ll add) {
        seg[v]+=add*(range_coords[r+1]-range_coords[l]);
        lazy_sum[v]+=add;
    }

    inline void push(int v,int l,int r) {
        if(lazy_sum[v]==0) return;
        int m=(l+r)/2;
        apply(v*2,l,m,lazy_sum[v]);
        apply(v*2+1,m+1,r,lazy_sum[v]);
        lazy_sum[v]=0;
    }

    void update(int v,int l,int r,int ql,int qr,ll add) {
        if(ql>qr) return;
        if(ql==l && qr==r){ 
            apply(v,l,r,add); 
            return; 
        }
        push(v,l,r);
        int m=(l+r)/2;
        update(v*2,l,m,ql,min(qr,m),add);
        update(v*2+1,m+1,r,max(ql,m+1),qr,add);
        seg[v]=seg[v*2]+seg[v*2+1];
    }

    ll query(int v,int l,int r,int ql,int qr) {
        if(ql>qr) return 0;
        if(ql==l && qr==r) return seg[v];
        push(v,l,r);
        int m=(l+r)/2;
        return query(v*2,l,m,ql,min(qr,m)) + query(v*2+1,m+1,r,max(ql,m+1),qr);
    }
};

struct Query {
    char type;
    ll l, r, k;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n,q; cin>>n>>q;
    vector<Query> queries(q);
    set<ll> ranges_set;
    
    for (auto &[type, l, r, k] : queries) {
        cin>>type>>l>>r;
        if (type == '!') {
            cin>>k;
        } else {
            k=0;
        }
        ranges_set.insert(l);
        ranges_set.insert(r+1);
    }
    range_coords.assign(ranges_set.begin(), ranges_set.end());
    ll size = range_coords.size() - 1;
    if (size < 0) size = 0;
    SegTree_Lazy seg(size);

    for (auto &[type, l, r, k] : queries) {
        auto it_l = lower_bound(range_coords.begin(), range_coords.end(), l);
        auto it_r = lower_bound(range_coords.begin(), range_coords.end(), r+1);
        auto id_l = it_l - range_coords.begin();
        auto id_r = it_r - range_coords.begin();

        if (type == '!') {
            seg.add(id_l, id_r-1, k);
        } else {
            cout<<seg.sum(id_l, id_r-1)<<"\n";
        }
    }

    return 0;
}
