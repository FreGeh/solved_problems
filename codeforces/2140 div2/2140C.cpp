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
    ll NEG=LLONG_MIN/2;
    ll n;cin>>n;
    vector<ll> a(n,-1);
    ll sum=0;
    for (ll i=0;i<n;i++) {
        cin>>a[i];
        if (i&1) {
            sum-=a[i];
        } else {
            sum+=a[i];
        }
    }
    
    ll besteven=NEG, bestodd=NEG;
    ll bestchange=0;
    if(n & 1) {
        bestchange=n-1; 
    } else {
        bestchange=n-2;
    }

    for (ll i=0;i<n;i++) {
        if (i&1) { // odd
            bestchange=max(bestchange, besteven + i + 2*a[i]);
            bestodd=max(bestodd,2*a[i]-i);
        } else {
            bestchange=max(bestchange, bestodd + i - 2*a[i]);
            besteven=max(besteven,-2*a[i]-i);
        }
    }
    cout<<max(sum,sum+bestchange)<<"\n";
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
