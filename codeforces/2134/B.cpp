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
    ll n,k;cin>>n>>k;
    vector<ll> A(n);
    ll test=0;
    for (auto &a : A) {
        cin>>a;
        test=gcd(test, a);
    }
    if (test==1) {
        ll m=k+1;
        for (auto &a : A) {
            ll b = a%m;
            a=a+k*b;
        }
    }
    for (auto &a : A) {
        cout<<a<<" ";
    }
    cout<<"\n";

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
