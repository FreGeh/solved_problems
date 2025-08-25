#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,m; cin>>n>>m;
    multiset<int> T;
    for (int i=0;i<n;i++) {
        int x; cin>>x;
        T.insert(x);
    }
    for (int j=0;j<m;j++) {
        int offer; cin>>offer;
        auto it = T.upper_bound(offer);
        if (it == T.begin()) cout << -1 << "\n";
        else it--, cout << *it << "\n", T.erase(it);
    }
    return 0;
}

// also possible to change multiset to DESC sorting by setting multiset<int, greater<int>> T; 
// so instead of lower_bound() finding the first element >= offer (since std::less<T> for ASC is default) it finds the first element <= offer
