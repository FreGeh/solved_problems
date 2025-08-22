#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n; cin>>n;
    set<int> seen;
    for (int i=0;i<n;i++) {
        int x; cin>>x;
        seen.insert(x);
    }
    cout << seen.size();
    return 0;
}

// no need to check if value already inside there, just insert into set for eb