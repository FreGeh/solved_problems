/**
 *      author:  gemtec
 *      created: 17.01.2026 13:19:48
 *      link:
 *      idea:
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n, k, x; cin>>n>>k>>x;
    vector<ll> liquid(n);
    for (auto &l : liquid) {
        cin>>l;
    }
    sort(liquid.begin(), liquid.end());
    ll total = 0;
    ll res=n-k;
    bool found=false;
    for (ll i=0; i<k; i++) {
        total+=liquid[k-i-1];
        if (total>=x) {
            found=true;
            res+=i+1;
            break;
        }
    }
    if (found) cout<<res<<"\n";
    else cout<<-1<<"\n";

    return 0;
}