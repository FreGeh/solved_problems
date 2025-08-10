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
    int n; cin >> n;
    if (n==2) {
        cout << -1 << " " << 2 << "\n";
    }
    if (n==3) {
        cout << -1 << " " << 3 << " " << -1 << "\n";
    }
    if (n>3) {
        cout << -1;
        for (int i=0;i<n-2;i=i+2) {
                cout << " " << 3 ;
                cout << " " << -1;
        }
        if (n % 2 ==0) {
            cout << " " << 2;
        }
        cout << "\n";  
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
