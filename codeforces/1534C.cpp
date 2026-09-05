#include "bits/stdc++.h"
using namespace std;
#define ll long long
 
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) do { } while(0)
#endif
 
ll MOD = 1e9+7;
 
ll pw (ll x, ll y){
    if (y == 0)return 1;
    if (y == 1)return x % MOD;
    ll res = pw (x,y/2);
    res = (res * res)%MOD;
    if (y&1) res = (res * x)% MOD;
    return res;
}
 
int n;
int a[400010];
int b[400010];
int vis [400020];
 
void solve() {
    cin >>n;
    for (int i=0;i<n;i++){
        cin >>a[i];
        vis[i]=0;
        b[i]=0;
    }
    vis[n]=0;
    b[n]=0;
    for (int i=0;i<n;i++){
        int z;
        cin >>z;
        b[a[i]]=z;
    }
    ll ans = 0;
    for (int i=0;i<n;i++){
        if (!vis[a[i]]){
            // cout <<a[i]<<" NOT VIS"<<endl;
            ans ++;
            int nod = a[i];
            while (!vis[nod]){
                // cout <<nod<<" DONE"<<endl;
                vis[nod]=1;
                nod = b[nod];
            }
        }
    }
    cout <<pw (2,ans)<<endl;
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