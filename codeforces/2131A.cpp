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
    vector<int> A(n), B(n);
    for (auto &a : A) {
        cin>>a;
    }
    for (auto &b : B) {
        cin>>b;
    }
    int count = 0;
    for (int i=0;i<n;i++) {
        if (A[i]>B[i]) {
            count += A[i]-B[i];
        }
    }
    cout << count+1 << "\n";
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
