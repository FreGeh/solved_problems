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
    int a,b,c,d;cin>>a>>b>>c>>d;
    if ((max(a,b) <= 2*min(a,b) + 2) && (max(c-a,d-b) <= 2*min(c-a,d-b) + 2)) {
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
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
