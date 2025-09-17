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
    int n;cin>>n;
    string s; cin>>s;
    int sum0=0;
    for (char c : s) {
        if (c=='0') {
            sum0++;
        }
    }
    string corr;
    corr.append(sum0, '0');
    corr.append(n - sum0, '1');
    int diff = 0;
    for (int i=0;i<n;i++) {
        if (s[i]!=corr[i]) diff++;
    }
    // build correct bit string and then compare differences and divide that through 2
    cout<<diff/2<<"\n";
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
