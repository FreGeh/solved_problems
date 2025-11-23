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
    ll k,x;cin>>k>>x;
    ll cur=x;
    ll target= 1LL << k;
    ll total= 1LL << (k+1);
    
    vector<int> path;
    while (cur!=target) {
        if (cur<target) {
            cur*=2;
            path.push_back(1);
        } else {
            cur=2*cur-total;
            path.push_back(2);
        }
    }
    cout<<path.size()<<"\n";
    reverse(path.begin(), path.end());
    for (auto p : path) {
        cout<<p<<" ";
    }
    cout<<"\n";
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
