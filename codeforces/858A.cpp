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
    ll n,k;
    cin >>n>>k;

    ll z = 1;
    for (int i=0;i<k;i++){
       z*=10;
    }

    //n*=z;
    ll gcd = __gcd(n,z);

    n *= z/gcd;
    cout << n<<endl;
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
