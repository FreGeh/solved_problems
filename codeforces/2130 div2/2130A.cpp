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
    int totalsum =0;
    for (int i=0;i<n;i++) {
        int x;
        cin>>x;
        totalsum+=x;
        if (x==0) {
            totalsum+=1;
        }
    }
    cout<<totalsum<<"\n";
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
