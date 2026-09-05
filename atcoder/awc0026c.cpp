/**
 *      author:  gemtec
 *      created: 16.03.2026 12:15:02
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

    ll n,t,e; cin>>n>>t>>e;
    vector<ll> P(n);
    for (auto &p : P) {
        cin>>p;
    }
    sort(P.begin(),P.end());
    ll total=0;
    int i=0;
    while (total+t*P[i]<=e && i<n) {
        total+=t*P[i];
        i++;
    }
    cout<<i;

    return 0;
}