#include "bits/stdc++.h"
using namespace std;
#define ll long long

// Conditional compilation
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) do { } while(0)
#endif

struct SegTree {
    int N;
    vector<int> tree;
    const int NEG = -1e9;

    void initialize(int n) {
        N=1;
        while (N < n) {
            N <<= 1;
        }
        tree.assign(2*N, NEG);
    }
    // set leaf tree[position] = val
    void update(int position, int val) {
        int i = position+N;
        tree[i] = val;
        for (i >>= 1; i; i >>= 1) {
            tree[i] = max(tree[i<<1], tree[i<<1|1]);
        }
    }
    // return max value for query from l to r inclusive
    int query(int l, int r) {
        int res = NEG;
        int L = l+N, R = r+N+1;
        while (L < R) {
            if (L & 1) res = max(res, tree[L++]);
            if (R & 1) res = max(res, tree[--R]);
            L >>= 1; R >>= 1;
        }
        return res;
    }
};

void solve() {
    int n,q;cin>>n>>q;
    vector<int> A(n);
    for (auto &a : A) {
        cin>>a;
    }
    vector<tuple<int,int,int>> query;
    for (int i=0;i<q;i++) {
        int l,r;cin>>l>>r;l--;r--;
        query.push_back({r,l,i});
    }
    sort(query.begin(), query.end());

    vector<int> prevGreater(n,-1),nextSmaller(n,n);
    prevGreater[0]=-1;
    vector<int> stack;
    for (int i=0;i<n;i++) {
        while (!stack.empty() && A[stack.back()]<=A[i]) {
            stack.pop_back();
        }
        prevGreater[i]=stack.empty()? -1 : stack.back();
        stack.push_back(i);
    }
    vector<int> stack2;
    for (int i=n-1;i>=0;i--) {
        while (!stack2.empty() && A[stack2.back()]>=A[i]) {
            stack2.pop_back();
        }
        nextSmaller[i]=stack2.empty()? n : stack2.back();
        stack2.push_back(i);
    }
    vector<pair<int,int>> small;
    for (int i=0;i<n;i++) {
        small.push_back({nextSmaller[i],i});
    }
    sort(small.begin(), small.end());

    SegTree seg; seg.initialize(n);
    vector<string> answer(q);
    int counter=0;
    for (auto [r,l,i] : query) {
        while (counter<n && small[counter].first<=r) {
            int id=small[counter].second;
            seg.update(id, prevGreater[id]);
            counter++;
        }
        int get = seg.query(l,r);
        answer[i]=(get>=l? "NO":"YES");
    }
    for (auto a : answer) {
        cout<<a<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    int tests; cin >> tests;
    while (tests-- > 0) solve();
    return 0;
}
