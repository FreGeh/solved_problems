/**
 *      author:  gemtec
 *      created: 14.03.2026 15:35:23
 *      link:
 *      idea:
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long


void solve() {
    map<int,int> color;
    int n; cin>>n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int a; cin>>a;
            color[a]++;
        }
    }
    bool poss=true;
    for (auto &c : color) {
        if (c.second > (n-1)*n) {
            poss = false;
            break;
        }
    }
    cout << (poss ? "YES" : "NO") << "\n";
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