/**
 *    author:  gemtec
 *    created: 03.12.2025 22:08:58
 *    problem: https://domjudge.iti.kit.edu/main/team/problems/46/statement
 *    goal: smallest difference between largest and smallest difficulty sum of valid partitions
**/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

// #ifdef DEBUG
// #include "templates/debug.h"
// #else
// #define debug(...) do { } while(0)
// #endif


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin>>n;
    vector<ll> pre(n+1, 0);
    for (int i=1; i<=n; i++) {
        ll x; cin>>x;
        pre[i]=pre[i-1]+x;
    }
    ll total=pre[n];

    auto diff = [&](int i, int j) -> ll {
        ll A = pre[i];
        ll B = pre[j]-pre[i];
        ll C = total - pre[j];
        return max({A,B,C})-min({A,B,C});
    };
    auto dist = [&](int i, int j) -> ll {
        return llabs(2*pre[j] - (total+pre[i]));
    };

    ll ans=LONG_LONG_MAX;
    int j=2;
    for (int i=1; i<=n-2; i++) {
        j=max(j, i+1);
        while (j < n-1 && dist(i,j+1) <= dist(i,j)) j++; //solange wir näher an gute einteilung kommen, erhöhen wir punkt für zweiten cut

        if (j-1>i && j-1<=n-1) ans=min(ans, diff(i,j-1));
        if (j>i && j<=n-1) ans=min(ans, diff(i,j));
        if (j+1>i && j+1<=n-1) ans=min(ans, diff(i,j+1));
    }
    cout<<ans<<endl;

    return 0;
}