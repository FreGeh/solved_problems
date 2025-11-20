#include "bits/stdc++.h"
using namespace std;
#define ll long long

struct SegTree {
    int len = 0;
    vector<ll> sum_t, min_t, max_t, first_el, last_el;
    vector<bool> decreasing;

    void pull(int v) {
        sum_t[v] = sum_t[v * 2] + sum_t[v * 2 + 1];
        min_t[v] = min(min_t[v * 2], min_t[v * 2 + 1]);
        max_t[v] = max(max_t[v * 2], max_t[v * 2 + 1]);
        first_el[v] = first_el[v*2];
        last_el[v] = last_el[v*2+1];
        decreasing[v] = (decreasing[v * 2] && decreasing[v * 2 + 1] && (last_el[v * 2] > first_el[v * 2 + 1]));
    }

    SegTree(int n = 0) {
        if (n > 0) init(n);
    }

    void init(int n) {
        len = n;
        sum_t.assign(2 * len, 0);
        min_t.assign(2 * len, LLONG_MAX);
        max_t.assign(2 * len, LLONG_MIN);
        first_el.assign(2 * len, 0);
        last_el.assign(2 * len, 0);
        decreasing.assign(2 * len, true);
    }

    void build(const vector<ll>& a) {
        init((int)a.size());
        for (int i = 0; i < len; ++i) {
            sum_t[len + i] = min_t[len + i] = max_t[len + i] = first_el[len + i] = last_el[len + i] = a[i];
        }
        for (int i = len - 1; i > 0; --i) {
            pull(i);
        }
    }

    void set(int index, ll new_val) {
        index += len;
        sum_t[index] = min_t[index] = first_el[index] = last_el[index] = max_t[index] = new_val;
        for (index /= 2; index >= 1; index /= 2) {
            pull(index);
        }
    }

    // range queries [left, right)

    ll query_sum(int left, int right) {
        ll res = 0;
        for (left += len, right += len; left < right; left /= 2, right /= 2) {
            if (left % 2 == 1) res += sum_t[left++];
            if (right % 2 == 1) res += sum_t[--right];
        }
        return res;
    }

    ll query_min(int left, int right) {
        ll res = LLONG_MAX;
        for (left += len, right += len; left < right; left /= 2, right /= 2) {
            if (left % 2 == 1) res = min(res, min_t[left++]);
            if (right % 2 == 1) res = min(res, min_t[--right]);
        }
        return res;
    }

    ll query_max(int left, int right) {
        ll res = LLONG_MIN;
        for (left += len, right += len; left < right; left /= 2, right /= 2) {
            if (left % 2 == 1) res = max(res, max_t[left++]);
            if (right % 2 == 1) res = max(res, max_t[--right]);
        }
        return res;
    }

    bool strictly_decreasing(int left, int right) {
        ll res=true;
        for (left += len, right += len; left < right; left /= 2, right /= 2) {
            if (left % 2 == 1) {
                res = decreasing[left++];
            }
            if (!res) return false;
            if (right % 2 == 1) {
                res = decreasing[--right];
            }
            if (!res) return false;
        }
        return res;
    }
};

void solve() {
    int n,q;cin>>n>>q;
    vector<ll> heights(n);
    for (auto &h : heights) {
        cin>>h;
    }
    SegTree seg;
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
            seg.set(index,height);
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
