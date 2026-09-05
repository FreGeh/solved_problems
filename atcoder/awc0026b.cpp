/**
 *      author:  gemtec
 *      created: 16.03.2026 12:05:15
 *      link:
 *      idea:
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n,k;cin>>n>>k;
    vector<ll> A(n);
    for (int i=0; i<n; i++) {
        cin>>A[i];
    }
    bool tak = false;
    ll s1=0,s2=0;
    for (int i=0; i<n; i++) {
        if (s1+A[i]<=k) { 
            s1+= A[i];
            // cout << s1 << "\n";
        } else {
            s2+= A[i];
            // cout << s2 << "\n";
        }
    }
    if (s1>s2) cout << "Takahashi" << "\n";
    else if (s1<s2) cout << "Aoki" << "\n";
    else cout << "Draw" << "\n";

    return 0;
}