#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;cin>>n;
    vector<int> A(n);
    for (auto &a : A) {
        cin>>a;
    }

    vector<ll> seen(n);
    seen[0]=1;
    ll res=0,pref=0;
    for (auto &a : A) {
        pref+=a;
        res+=seen[(pref%n+n)%n];
        seen[(pref%n+n)%n]++;
    }
    cout<<res;

    return 0;
}
