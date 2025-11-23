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
    ll a,b,a1,b1;
    ll x,y;

    cin >>a>>b>>a1>>b1;
    cin >>x>>y;

    ll dx = abs (a-a1);
    if (dx % x){
        cout <<"NO"<<endl;
        return;
    }
    dx /= x;

    ll dy = abs (b-b1);
    if (dy % y){
        cout <<"NO"<<endl;
        return;
    }
    dy /= y;

    if (abs (dy-dx) % 2){
        cout <<"NO"<<endl;
        return;
    }
    cout <<"YES"<<endl;

}

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    // int tests; cin >> tests;
    // while (tests-- > 0) solve();
    solve();
    return 0;
}
