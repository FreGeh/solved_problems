#include "bits/stdc++.h"
using namespace std;
#define ll long long


void solve() {
    int n,q;cin>>n>>q;
    vector<ll> heights(n);
    for (auto &h : heights) {
        cin>>h;
    }
    SegTree_Lazy seg;
    seg.init(n);
    seg.build(heights);
    for (int i=0;i<q;i++) {
        char type; cin>>type;
        if (type == 'B') {
            ll index_1,index_2;cin>>index_1>>index_2;
            index_1--; index_2--; // my segtree is zero-indexed
            cout<<(seg.strictly_decreasing(index_1, index_2)? "YES":"NO")<<"\n";
        } else {
            ll index,height;cin>>index>>height;
            ll change = seg.point_get(index);
            seg.add(index,index,height-change);
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
