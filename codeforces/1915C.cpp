#include "bits/stdc++.h"
using namespace std;
#define ll long long

void solve() {
    int n;cin>>n;
    ll sum=0;
    for (int i=0;i<n;i++) {
        int inp;cin>>inp;
        sum+=inp;
    }
    ll l=1,r=10e8;
    while (l<=r) {
        ll m=l+(r-l)/2;
        if (sum/m < m) {
            r=m-1;
        } else {
            l=m+1;
        }
    }
    l--;
    cout<<((sum==l*l)?"YES":"NO")<<endl;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int tests; cin >> tests;
    while (tests-- > 0) solve();
    return 0;
}
