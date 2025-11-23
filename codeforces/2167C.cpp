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
    vector<int> toys(n);
    bool even=false,uneven=false;
    for (int i=0;i<n;i++) {
        cin>>toys[i];
        if (toys[i] % 2==0) {
            even=true;
        } else {
            uneven=true;
        }
    }
    if (even && uneven) {
        sort(toys.begin(), toys.end());
    }
    for (auto toy : toys) {
        cout<<toy<<" ";
    }
    cout<<"\n";
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
