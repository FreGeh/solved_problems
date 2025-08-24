#include "bits/stdc++.h"
using namespace std;
#define ll long long

const int MAX=1000000000;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int l=1, r=MAX;

    while (l <= r) {
        int mid = l+(r-l)/2;
        cout << "? " << mid << "\n";
        cout.flush();
        string ans; cin>>ans;
        if (ans=="YES") {
            l=mid+1;
        } else {
            r=mid-1;
        }
    }
    cout << "! " << l;
    cout.flush();

    return 0;
}
