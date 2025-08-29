#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n; cin>>n;
    int xorout = 0;
    for (int i=1;i<n+1;i++) {
        xorout ^= i;
    }
    for (int i=0;i<n-1;i++) {
        int tosee; cin >> tosee;
        xorout ^= tosee;
    }
    cout << xorout;
    return 0;
}
/* Previous code before fix and understanding XOR way

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n; cin>>n;
    set<int> seen;
    for (int i=1;i<n+1;i++) {
        seen.insert(i);
    }
    for (int i=0;i<n-1;i++) {
        int tosee; cin >> tosee;
        seen.erase(tosee);
    }
    for (auto entry :seen) {
        cout << entry << "\n";
    }
    return 0;
}
*/