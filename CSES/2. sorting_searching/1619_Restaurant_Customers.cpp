#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;cin>>n;
    vector<pair<ll,bool>> time;
    for (int i=0;i<n;i++) {
        ll a,b; cin>>a>>b;
        time.push_back({a,true});
        time.push_back({b,false});
    }
    sort(time.begin(), time.end());
    int cur=0, sol=0;
    for (auto &[point,type] : time) {
        if (type) cur++;
        else cur--;
        sol=max(cur,sol);
    }
    cout<<sol<<endl;

    return 0;
}
