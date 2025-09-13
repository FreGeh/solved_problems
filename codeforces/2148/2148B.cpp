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
    int n,m,x,y;cin>>n>>m>>x>>y;
    for (int i=0;i<n;i++) {
        int y;cin>>y;
    }
    for (int i=0;i<m;i++) {
        int y;cin>>y;
    }
    cout<<n+m<<"\n";
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
