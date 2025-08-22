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
    int N; cin>>N;
    vector<int> vases(N);
    cin>>vases[0];
    int smallestfirst = vases[0];
    int smallestsecond = 1000;
    int smallestcombination = 2000;
    for (int i=1;i<N;i++) {
        cin>>vases[i];
        if (vases[i] < smallestfirst) {
            smallestsecond = smallestfirst;
            smallestfirst = vases[i];
        } else if (vases[i] < smallestsecond) {
            smallestsecond = vases[i];
        }
        if ((vases[i]/2)+vases[i-1] < smallestcombination) {
            smallestcombination = (vases[i]/2)+vases[i-1];
        }
    }
    cout << min(smallestfirst+smallestsecond, smallestcombination) << "\n";
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
