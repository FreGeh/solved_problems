#include "bits/stdc++.h"
using namespace std;
#define ll long long

// Conditional compilation
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) do { } while(0)
#endif

void solve() {
    ll n,k; cin>>n>>k;
    vector<ll> S(n),T(n);
    for (auto &s:S) {
        ll entry;
        cin>> entry;
        s = entry % k;
    }
    for (auto &t:T) {
        ll entry;
        cin>> entry;
        t = entry % k;
    }
    auto bucket = [&](ll x) -> ll {
        if (x == 0) {
            return 0;
        }
        if (k % 2 == 0 && x == k/2) {
            return k/2;
        }
        return min(x,k-x);
    };
    unordered_map<ll,ll> Scount(2*n),Tcount(2*n);
    for (int i=0;i<n;i++) {
        Scount[bucket(S[i])]++;
        Tcount[bucket(T[i])]++;
    }
    if (Scount == Tcount) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0) solve();

    return 0;
}
