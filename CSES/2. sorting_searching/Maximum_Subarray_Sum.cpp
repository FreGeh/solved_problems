#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;cin>>n;
    ll cur=0, best=LLONG_MIN;
    for (int i=1;i<=n;i++) {
        ll x;
        cin>>x;
        cur=max(x,cur+x);
        best=max(best,cur);
    }
    cout<<best;

    return 0;
}
