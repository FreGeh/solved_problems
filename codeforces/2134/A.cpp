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
    int n,a,b;cin>>n>>a>>b;
    if ((n-b)%2 !=0) {
        cout << "NO\n";
    }
    else if (a<=b || (a-b)%2==0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
