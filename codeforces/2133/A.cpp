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
    int n; cin>>n;
    unordered_set<int> seen;
    bool dupl=false;
    for (int i=0;i<n;i++) {
        int x; cin>>x;
        if (seen.count(x)) {
            dupl=true;
        }
        seen.insert(x);
    }
    if (dupl) {
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

    int tests;
    cin >> tests;

    while (tests-- > 0) solve();

    return 0;
}
