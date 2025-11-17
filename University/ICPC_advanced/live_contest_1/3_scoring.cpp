#include "bits/stdc++.h"
using namespace std;
#define ll long long


void solve() {
    int n; cin>>n; // n teams, n! games
    vector<ll> soccer(n), chess(n);
    for (auto &p : soccer) { //winner=3, draw=1, loser=0
        double l;
        cin>>l;
        p=l*2;
    }
    for (auto &p : chess) { //winner=1, draw=0.5, loser=0
        double l;
        cin>>l;
        p=l*2;
    }
    for (int i=0;i<n;i++) {
        int draw=0, lose=0, win=0;
        draw=(3*chess[i]-soccer[i]);
        win=(soccer[i]-2*draw)/6;
        lose=n-1-win-draw;
        cout<<win<<" "<<draw<<" "<<lose<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    
    solve();
    return 0;
}
