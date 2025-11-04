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
    vector<int> A(n);
    for (int i=0;i<n;i++) {
        cin>>A[i];
    }
    int sol=0;
    int prev=A[0];
    for (int i=1; i<n-1;i++) {
        if ((prev<A[i] && A[i]>A[i+1]) || (prev>A[i] && A[i]<A[i+1])) {
            sol++;
        }
        prev=A[i];
    }
    cout<<sol<<"\n";
}

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    solve();
    return 0;
}
