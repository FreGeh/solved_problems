/**
 *      author:  gemtec
 *      created: 17.01.2026 14:03:12
 *      link:
 *      idea:
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

template <class T>
struct Fenwick { // 0-indexed
    int n;
    vector<T> bit;

    Fenwick() : n(0) {}
    Fenwick(int n_) { init(n_); }

    void init(int n_) {
        n = n_;
        bit.assign(n+1, T(0));
    }

    void add(int i, T delta) { // a[i] += delta
        for (i++; i<=n; i+=i&-i) bit[i] += delta;
    }

    T query(int i) const { // sum of a[0..i-1]
        T res = T(0);
        for (; i>0; i-=i&-i) res += bit[i];
        return res;
    }

    T query(int l, int r) const { // sum of a[l..r-1]
        return query(r) - query(l);
    }

    // Returns smallest i such that sum([0, i]) >= k
    // Requires: bit values >= 0
    int lower_bound(T k) const {
        if (k <= 0) return 0;

        int idx = 0;
        T cur = T(0);

        int step = 1;
        while ((step<<1) <= n) step<<=1;

        for (; step > 0; step>>=1) {
            int nxt = idx+step;
            if (nxt <= n && cur+bit[nxt] < k) {
                cur += bit[nxt];
                idx = nxt;
            }
        }
        return idx; // Returns n if sum < k
    }

    T total() const { return query(n); }
};


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin>>n;
    string s; cin>>s;
    vector<ll> pre(n+1, 0);
    for (int i=0;i<n;i++) {
        char c=s[i];
        pre[i+1]=pre[i];
        if (c=='A') pre[i+1]++;
        else if (c=='B') pre[i+1]--;
    }

    vector<ll> vals = pre;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    auto id = [&](ll x) {
        return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin());
    };
    Fenwick<int> bit(vals.size());
    
    ll res=0;
    for (int j=0; j<=n; j++) {
        int idx = id(pre[j]);
        res+=bit.query(idx);
        bit.add(idx, 1);
    }
    cout<<res;

    return 0;
}