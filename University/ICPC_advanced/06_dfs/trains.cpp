/**
 *      author:  gemtec
 *      created: 13.02.2026 14:32:45
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    ll mod = 1e9+7;
    vector<int> deg(n+1,0);
    for (int i=0; i<n-1; i++) {
        int u,v;
        cin>>u>>v;
        deg[u]++;
        deg[v]++;
    }
    
    vector<ll> fact(n+1);
    fact[0]=1;
    for (int i=1; i<=n; i++) {
        fact[i]=(fact[i-1]*i)%mod;
    }

    ll ans = (2LL*(n-1))%mod;
    for (int i=1; i<=n; i++) {
        ans=(ans*fact[deg[i]-1])%mod;
    }

    cout<<ans<<"\n";
    return 0;
}