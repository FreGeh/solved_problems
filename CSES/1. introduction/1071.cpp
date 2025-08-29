#include "bits/stdc++.h"
using namespace std;
#define ll long long

// Conditional compilation
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) do { } while(0)
#endif

ll solve() {
    ll y,x; cin>>y>>x;
    ll big = max(y,x);
    ll amount = big * big;
    if (y == big) {
        if (y & 1) {
            return amount  - (y-1)*2 + x-1;
        } else {
            return amount - x+1;
        }
    } else {
        if (x & 1) {
            return amount  - y+1;
        } else {
            return amount-x+1-(x-y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0) cout << solve() << "\n";

    return 0;
}

/* --- LEARNINGS: ---
if you use ll make sure the method is actually also returning ll's
*/