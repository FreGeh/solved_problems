/**
 *    author:  gemtec
 *    created: 02.12.2025 14:08:58
 *    problem: https://domjudge.iti.kit.edu/main/team/problems/46/statement
 *    goal: smallest difference between largest and smallest difficulty sum of valid partitions
**/
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

    int n; cin>>n;
    vector<ll> pre(n+1, 0);
    for (int i=1; i<=n; i++) {
        ll x; cin>>x;
        pre[i]=pre[i-1]+x;
    }
    ll total=pre[n];

    ll ans=LONG_LONG_MAX;
    for (int i=1; i<=n-2; i++) {
        ll P = pre[i];
        ll rem = total-P;

        ll target = P+rem/2;

        auto it = lower_bound(pre.begin()+i+1, pre.begin()+n, target);
        if (it != pre.begin()+n) {
            ll cur = *it;
            ll B = cur-P;
            ll A = total-cur;
            ll dif = max({A,B,P})-min({A,B,P});
            ans=min(ans, dif);
        }
        if (it != pre.begin()+i+1) {
            ll cur = *(it-1);
            ll B = cur-P;
            ll A = total-cur;
            ll dif = max({A,B,P})-min({A,B,P});
            ans=min(ans, dif);
        }
    }
    cout<<ans<<endl;

    return 0;
}