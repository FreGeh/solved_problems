/**
 *      author:  gemtec
 *      created: 21.09.2026 17:28:09
 *      link:
 *      idea:
 *      learning:
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define int long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

// credit: adapted from tourist_algos
struct Factorizer {
    int n;
    vector<int> spf;
    vector<int> primes;

    Factorizer() : n(0) {}
    Factorizer(int n_) { init(n_); }

    void init(int n_) {
        n = n_;
        spf.assign(n+1, 0);
        primes.clear();

        for (int i=2; i<=n; i++) {
            if (spf[i] == 0) {
                spf[i] = i;
                primes.push_back(i);
            }

            for (int p : primes) {
                if (p > spf[i] || 1LL*i*p > n) break;
                spf[i*p] = p;
            }
        }
    }

    bool is_prime(int x) const {
        return x >= 2 && spf[x] == x;
    }

    int smallest_prime_factor(int x) const {
        return spf[x];
    }

    int largest_prime_factor(int x) const {
        int p = 1;
        while (x > 1) {
            p = spf[x];
            x /= spf[x];
        }
        return p;
    }

    vector<pair<int,int>> factorize(int x) const {
        vector<pair<int,int>> res;

        while (x > 1) {
            int p = spf[x];
            int cnt = 0;

            while (x % p == 0) {
                x /= p;
                cnt++;
            }

            res.push_back({p, cnt});
        }

        return res;
    }

    vector<int> divisors(int x) const {
        auto fac = factorize(x);
        vector<int> res = {1};

        for (auto [p, cnt] : fac) {
            int sz = res.size();
            int mul = 1;

            for (int e=1; e<=cnt; e++) {
                mul *= p;
                for (int i=0; i<sz; i++)
                    res.push_back(res[i] * mul);
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};

Factorizer f;
vector<int> dp;
int k=0;

int minOps(int x) {
  if (x<=k) return 0;
  if (dp[x]!=-1) return dp[x];
  
  int res=LLONG_MAX;
  for (auto [p,num] : f.factorize(x)) {
    res=min(res, p*minOps(x/p) + 1);
  }
  dp[x]=res;
  return res;
}

void solve() {
  int n;cin>>n>>k;
  dp = vector<int>(n+1, -1);

  int count=0; // min num of ops until all from A are <= k
  for (int i=0;i<n;i++) {
    int a;
    cin>>a;
    count += minOps(a);
  }

  cout<<count<<endl;
}

signed main() {
  ios::sync_with_stdio(false);
#ifndef DEBUG
  cin.tie(nullptr);
#endif

  f = Factorizer(200000);

  int tests; cin >> tests;
  while (tests-- > 0) solve();
  return 0;
}