#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    ll n; cin>>n;
    if (n==1) {
        cout << 1;
    } else {
        if (n>3) {
            for (ll i=n-1;i>0;i=i-2) {
                cout << i << " ";
            }
            for (ll i=n;i>0;i=i-2) {
                cout << i << " ";
            }
        } else {
            cout << "NO SOLUTION";
        }
    }

    return 0;
}