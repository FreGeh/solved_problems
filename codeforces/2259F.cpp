/**
 *      author:  gemtec
 *      created: 05.09.2026 18:09:41
 *      link:
 *      idea:
 *      learning:
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

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

void solve() {
  int n;cin>>n;
  vector<int> A(n);
  ll ones=0, zeroes=0;
  ll tot_ones=0, tot_zeroes=0;
  ll inversions=0;
  for (int i=0;i<n;i++) {
    int a;cin>>a;
    A[i]=a;
    if (a == 1) {
      ones++;
      tot_ones++;
    } else {
      inversions+=ones;
      tot_zeroes++;
    }
  }
  string s;cin>>s;
  
  set<int> one, zero;
  Fenwick<ll> fw(4*n);
  vector<ll> res;
  res.push_back(inversions);

  int l=n;
  int r=2*n-1;

  for (int i=0;i<n;i++) {
    int init=n+i;
    fw.add(init,1);

    if (A[i]==1) one.insert(init);
    else zero.insert(init);
  }

  for (int i=0;i<n;i++) {
    if (s[i]=='1') { // forward: zeroes - zeroes before first one
      if (!one.empty()) {
        int firstone = *one.begin();
        ll zero_count = fw.query(firstone);
        ll del = tot_zeroes - zero_count;

        inversions-=del;

        one.erase(firstone);
        fw.add(firstone,-1);
        r++;
        one.insert(r);
        fw.add(r,1);
      }
    } else { // reverse
      if (!zero.empty()) {
        int lastzero = *zero.rbegin();
        ll one_count = n-fw.query(lastzero+1);
        ll del = tot_ones - one_count;

        inversions-=del;

        zero.erase(lastzero);
        fw.add(lastzero,-1);
        l--;
        zero.insert(l);
        fw.add(l,1);
      }
    }
    res.push_back(inversions);
  }
  for (ll &r : res) {
    cout<<r<<" ";
  }
  cout<<endl;
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