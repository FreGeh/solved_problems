/**
 *      author:  gemtec
 *      created: 16.03.2026 12:25:31
 *      link:
 *      idea:
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,k; cin>>n>>k;
    vector<pair<int,int>> seg;
    for (int i=0; i<n;i++) {
        int l,r; cin>>l>>r;
        seg.push_back({l,1});
        seg.push_back({r,-1});
    }
    sort(seg.begin(), seg.end());

    ll cur=0;
    ll sol=0;
    for (auto &[pos,pm] : seg) {
        bool alr = (cur>=k);
        cur+=pm;
        if (!alr && cur>=k) {
            sol-=pos;
        } else if (alr && cur<k) {
            sol+=pos;
        }
    }
    cout<<sol;
    

    return 0;
}