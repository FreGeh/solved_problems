#include "bits/stdc++.h"
using namespace std;
#define ll long long

// Conditional compilation
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) do { } while(0)
#endif

int solve() {
    ll a,b;cin>>a>>b;
    int k=0;
    ll tmp=b;
    while (tmp % 2==0) {
        tmp/=2; k++;
    }

    if (a%2==0 && b%2==1) {
        cout<<-1;
    }
    else if (a%2==1 && b%2==1) {
        cout<<a*b+1;
    }
    else if (a%2==1 && b%2==0) {
        if (k >=2) cout<<a*(b/2)+2;
        else cout<<-1;
    }
    else if (a%2==0 && b%2==0) {
        cout<<a*(b/2)+2;
    }
    cout<<"\n";
    return 0;
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
