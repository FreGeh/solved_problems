#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) do { } while(0)
#endif

ll solve() {
    int n;cin>>n;
    ll k;cin>>k;
    vector<ll> A(n);
    for (int i=0;i<n;i++) {
        cin>>A[i];
    }
    sort(A.begin(), A.end());

    ll prev=0, got=0;
    ll ans=0;
    for (int i=0; i<n; i++) {
        ll dif=A[i]-prev;
        got+=dif*(n-i);
        if (got>=k) {
            ans=k+i;
            return ans;
        }
        prev=A[i];
    }
    return k+n-1;
 }

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    int tests; cin >> tests;
    while (tests-- > 0) cout<<solve()<<endl;
    return 0;
}
