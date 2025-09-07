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
    int n; cin>>n;
    vector<vector<int>> seen(n+1);
    for (int i=0; i<n; i++) {
        int inp;cin>>inp;
        seen[inp].push_back(i);
    }
    vector<int> A(n,-1);
    int label=1;
    for (int i=1;i<=n;i++) {
        int m = seen[i].size();
        if (m==0) continue;
        else if (m % i != 0) { cout<<"-1\n"; return 0; }
        else {
            for (int k=0; k<m; k+=i) {
                for (int j = 0; j < i; ++j) {
                    A[seen[i][k+j]] = label;
                }
                ++label;
            }
        }
    }
    for (int i=0; i<n; i++) {
        cout << A[i]<<" ";
    }
    cout << '\n';
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
