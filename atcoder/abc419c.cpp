#include "bits/stdc++.h"
using namespace std;
#define ll long long

ll MAX = 1e9;
ll MIN = 1;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    ll N; cin>>N;
    ll lowest_row = MAX;
    ll lowest_col = MAX;
    ll highest_row = MIN;
    ll highest_col = MIN;
    for (ll i=0; i<N;i++) {
        ll row, col; cin >> row >> col;
        lowest_row=min(row, lowest_row);
        lowest_col=min(col, lowest_col);
        highest_row=max(row, highest_row);
        highest_col=max(col, highest_col);
    }
    ll delta_row=(highest_row - lowest_row + 1) / 2;
    ll delta_col=(highest_col - lowest_col+ 1) / 2;
    cout << max(delta_col, delta_row);

    return 0;
}
