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
    int n, s; cin>>n>>s;
    vector<int> A(n);
    int totalstraight = 0;
    int totalzero =0;
    int totalone =0;
    int totaltwo =0;
    for (int &a : A) {
        cin >> a;
        totalstraight= totalstraight + a;
        if (a==0) {
            totalzero++;
        } else if (a==1) {
            totalone++;
        } else if (a==2) {
            totaltwo++;
        }
    }
    // wenn s zu klein sowieso einfach gleich lassen
    if (s < totalstraight) {
        for (int a : A) {
            cout << a << " ";
        }
    }
    // wenn s gleich totalsum ist
    else if ((s - totalstraight) == 1) {
        while (totalzero--) cout << 0 << " ";
        while (totaltwo--) cout << 2 << " ";
        while (totalone--) cout << 1 << " ";
    } else {
        cout << -1;
    }
    cout << "\n";



}

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0) solve();

    return 0;
}
