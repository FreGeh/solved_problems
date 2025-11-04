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
    int n,k,x;cin>>n>>k>>x;
    vector<int> pos(n);
    for (auto &p : pos) {
        cin>>p;
    }
    sort(pos.begin(),pos.end());

    auto amount = [&](int d) {
        int count = max(0, pos[0] - d +1);

        for (int i=0;i<n-1;i++) {
            count += max(0, (pos[i+1]-d) - (pos[i]+d) +1);
        }

        count += max(0, x - pos[n-1] - d +1);

        return count;
    };

    int low=0;
    int high=1e9;

    while(low<high) {
        int mid = low + (high - low +1) / 2;

        if (amount(mid)>=k) {
            low=mid;
        }
        else {
            high=mid-1;
        }
    }

    // capture the exact positions
    set<int> output;
    for(int i=0;i<=pos[0]-low && (int)output.size()<k;i++) {
        output.insert(i);
    }
    for(int i=0;i<n-1;i++) {
        for(int j=pos[i]+low;j<=pos[i+1]-low && (int)output.size()<k;j++) {
            output.insert(j);
        }
    }
    for(int i=pos[n-1]+low;i<=x && (int)output.size()<k ;i++) {
        output.insert(i);
    }
    for (auto o : output) {
        cout<<o << " ";
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
