#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,x; cin>>n>>x;
    vector<int> A(n);
    for (auto &a : A) {
        cin>>a;
    }
    ll pref=0;
    ll res=0;
    map<ll,int> seen;
    seen[0] = 1;
    for (auto &a : A) {
        pref += a;
        res += seen[pref - x];
        seen[pref]++;
    }

    cout<<res;


    return 0;
}
