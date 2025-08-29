// https://usaco.org/index.php?page=viewproblem2&cpid=595
#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    
    int n;cin>>n;
    vector<ll> rem(7,-1);
    rem[0]=0;
    ll cur=0;
    ll res=0;
    for (int i=1;i<n+1;i++) {
        ll cow;
        cin>>cow;

        cur=(cur+cow)%7;
        // cout<<"cow is " << cow<< " cur is " << cur << "\n";
        if ((rem[cur])==-1) {
            rem[cur]=i;
        } else {
            res=max(res,i-rem[cur]);
        }
    }
    cout<<res<<"\n";

    return 0;
}
