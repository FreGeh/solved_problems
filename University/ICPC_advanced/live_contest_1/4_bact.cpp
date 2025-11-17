#include "bits/stdc++.h"
using namespace std;
#define ll long long


void solve() {
    int n,q; cin>>n>>q; // n teams, n! games
    vector<vector<pair<int,ll>>> gases(n);
    for (auto &gas : gases) {
        ll x; cin>>x;
        gas.push_back({1,x});
    }
    int cur_ph=2;
    for (int i=0;i<q;i++) {
        char type; cin>>type;
        if (type=='!') {
            int index,x;cin>>index>>x;
            gases[index-1].push_back({cur_ph++, x});
        } else { //<=t
            int index,t; cin>>index>>t;
            int l=-1, r=gases[index-1].size();
            while (r-l>1) {
                int m=l+(r-l)/2;
                //cout<<"left is "<<l<<" mid is "<<m<<" right is "<<r<<"\n";
                if (gases[index-1][m].first > t) {
                    r=m;
                } else {
                    l=m;
                }
            }
            //cout<<"left is "<<l<<" right is "<<r<<"\n";
            cout<<gases[index-1][l].second<<"\n";

        }
    }
    // gas 1 sol 55
    // 3 
}

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    
    solve();
    return 0;
}
