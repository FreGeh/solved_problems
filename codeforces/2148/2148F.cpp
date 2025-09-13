#include "bits/stdc++.h"
using namespace std;
#define ll long long

// Conditional compilation
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) do { } while(0)
#endif

// not working since i still need to add proper way to distinguish between best Arrays, im so dumb
void solve() {
    int n;cin>>n;
    vector<int> lengths(n);
    int maxlength=0;
    vector<vector<int>> A(n);
    for (int i=0;i<n;i++) {
        cin>>lengths[i];
        A[i].resize(lengths[i]);
        for (int j=0;j<lengths[i];j++) {
            cin>>A[i][j];
        }
        maxlength=max(maxlength,(int)A[i].size());
    }

    vector<int> small(maxlength, INT_MAX);
    vector<int> best(maxlength, -1);
    for (int i=0;i<n;i++) {
        for (int j=0;j<lengths[i];j++) {
            if (A[i][j]<small[j]) {
                small[j]=A[i][j];
                best[j]=i; // thats not enough logic i rly need to add something here to make it distinguish the best array out of all with the same values
            }
        }
    }

    vector<int> res(maxlength);
    int i=0;
    while (i<maxlength) {
        int row=best[i];
        int k=i;
        if (row==-1) continue;
        while (k<A[row].size()) {
            res[k]=A[row][k];
            k++;
        }
        i=k;
    }


    for (int i=0;i<maxlength;i++) {
        cout<<res[i]<<" ";
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
