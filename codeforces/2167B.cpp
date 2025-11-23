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
    string s,t;cin>>s>>t;
    map<char,int> seen;
    for (auto a : t) {
        seen[a]++;
    }
    bool works=true;
    for (auto a : s) {
        if (seen[a]>0) {
            seen[a]--;
        } else {
            works=false;
            break;
        }
    }
    if (works) {
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
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
