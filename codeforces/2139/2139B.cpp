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
    ll n,m;cin>>n>>m;
    vector<ll> cakes(n);
    ll sum=0;
    for (auto &c : cakes) {
        cin>>c;
    }
    sort(cakes.begin(), cakes.end(), greater<ll>());
    ll k=min(n,m);
    for (ll i=0;i<k;i++) {
        sum+=cakes[i]*(m-i);
    }
    cout<<sum<<"\n";
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
