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
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i=0; i<n; i++) cin >> nums[i];
    int maxi = nums[n-1];
    int boxes = (2*n)-(2*k);
    for (int i=0; i<boxes/2; i++) {
        maxi = max(maxi, nums[i]+nums[boxes-i-1]);
    }
    cout << maxi;
}

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    //int tests; cin >> tests;
    //while (tests-- > 0) solve();
    solve();
    return 0;
}
