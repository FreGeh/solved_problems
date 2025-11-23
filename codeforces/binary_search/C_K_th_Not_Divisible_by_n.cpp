#include "bits/stdc++.h"
using namespace std;
#define ll long long

ll find(ll l, ll r, ll k, ll n) {
    ll ans=0;
    while (l<=r) {
        ll m=l+(r-l)/2;
        if (m-(m/n)>=k) {
            ans=m;
            r=m-1;
        } else {
            l=m+1;
        }
    }
    return ans;
}

void solve() {
    ll n,k; cin>>n>>k;
    ll sol;
    if (n>k) {
        sol=k;
    } else {
        ll l=1,r=k*2;
        sol = find(l, r, k, n);
    }
    cout<<sol<<"\n";
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int tests; cin >> tests;
    while (tests-- > 0) solve();
    return 0;
}
// its also possible to do binary search over the segments which always have (n-1) non-dividable numbers since we multiply with n
// ll find(ll l, ll r, ll k, ll n) {
//     while (l<=r) {
//         ll m=l+(r-l)/2;
//         if ((n-1)*m>=k) {
//             r=m-1;
//         } else {
//             l=m+1;
//         }
//     }
//     return k-r*(n-1)+r*n;
// }

// void solve() {
//     ll n,k; cin>>n>>k;
//     ll sol;
//     if (n>k) {
//         sol=k;
//     } else {
//         ll l=1,r=(ll)1e9;
//         sol = find(l, r, k, n);
//     }
//     cout<<sol<<"\n";
// }