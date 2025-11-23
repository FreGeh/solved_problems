#include "bits/stdc++.h"
using namespace std;
#define ll long long

// Conditional compilation
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) do { } while(0)
#endif

int solve() {
    int n;cin>>n;
    vector<int> P(n+1),pos(n+1);
    for (int i=1;i<n+1;i++) {
        cin>>P[i];
        pos[P[i]]=i;
    }
    int left=pos[n], right=pos[n];
    for (int i=n-1;i>0;i--) {
        if (pos[i] == left-1) {
            left=pos[i];
        } else if (pos[i]==right+1) {
            right=pos[i];
        }
        else {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
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
