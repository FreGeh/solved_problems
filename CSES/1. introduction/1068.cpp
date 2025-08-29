#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    ll n; cin>>n;
    vector<ll> sequence;
    while (n != 1) {
        sequence.push_back(n);
        if (n & 1) {
            n = n*3 +1;
        } else {
            n=n/2;
        }
    }
    for (ll seq : sequence) {
        cout << seq << " ";
    }
    cout << 1;
    return 0;
}

/* --- LEARNINGS: ---
really look out for the data type for each
*/