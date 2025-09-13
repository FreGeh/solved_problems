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
    int n;cin>>n;
    ll sum=0;
    vector<int> odd;
    for (int i=0;i<n;i++) {
        int a;cin>>a;
        if (a&1) {
            odd.push_back(a);
        }
        sum+=a;
    }
    if (odd.size()>=1) {
        sort(odd.begin(), odd.end());
        int k= odd.size()/2;
        ll minus=0;
        for (int i=0;i<k;i++) {
            minus+=odd[i];
        }
        cout<<sum-minus<<"\n";
    } else {
        cout<<0<<"\n";
    }
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
