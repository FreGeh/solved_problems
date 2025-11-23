#include "bits/stdc++.h"
using namespace std;
#define ll long long


void solve() {
    int n;cin>>n;
    int l=0,r=n;
    while (l<=r) {
        int m=l+(r-l)/2;
        if (n/4>m) {
            l=m+1;
        } else {
            r=m-1;
        }
    }
    int chicken=(n-l*4)/2;
    cout<<l+chicken<<endl;
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
