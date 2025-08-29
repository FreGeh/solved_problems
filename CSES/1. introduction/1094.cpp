#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    ll n; cin>>n;
    ll prev; cin >> prev;
    ll count = 0;
    for (int i=0; i<n-1; i++) {
        ll cur; cin >> cur;
        if (prev > cur) {
            count += prev-cur;
            cur = prev;
        }
        prev = cur;
    }
    cout << count;
    return 0;
}

/* --- LEARNINGS: ---
once again use ll instead of int, really look out for that
*/