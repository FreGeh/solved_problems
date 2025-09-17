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
    string s;cin>>s;
    vector<int> prefix(n+1,0);
    for (int i=0; i<n;i++) {
        prefix[i+1]=prefix[i]+(s[i] == '1');
    }
    bool min_dif = true;
    for (int i=0; i+k<=n;i++) {
        if (prefix[i+k] - prefix[i] == k) {
            min_dif=false;
            break;
        }
    }
    if (!min_dif) {
        cout<<"NO\n";
    } else {
        cout<<"YES\n";
        int zero=n,one=1;
        for (int i=0; i<n;i++) {
            if (s[i] == '1') {
                cout<<one<<" ";
                one++;
            } else {
                cout<<zero<<" ";
                zero--;
            }
        }
        cout<<"\n";
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
