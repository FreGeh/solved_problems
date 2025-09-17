#include "bits/stdc++.h"
using namespace std;
#define ll long long

// Conditional compilation
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) do { } while(0)
#endif

void solve() {
    int n,k; cin>>n>>k;
    vector<ll> prices(n), discounts(k);
    ll sum=0;
    for (int i=0;i<n;i++) {
        cin>>prices[i];
        sum+=prices[i];
    }
    sort(prices.begin(), prices.end(), greater<ll>());
    // 18 9 7 3 2
    for (int i=0;i<k;i++) {
        cin>>discounts[i];
    }
    // 3 1 1
    sort(discounts.begin(), discounts.end());
    // 1 1 3
    int i=0;
        for (auto d : discounts) {
            if (i+(d-1)<n) {
                sum-=prices[i+(d-1)]; // 18, 9, 2
                i+=d;
            } else { 
                break;
            }
        }
    cout<<sum<<"\n";
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
