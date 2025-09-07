#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,x;cin>>n>>x;
    map<int,int> seen;
    for (int i=0;i<n;i++) {
        int y;
        cin>>y;
        if (seen.count(x-y)) {
            cout<<seen[x-y]<<" "<<i+1;
            return 0;
        }
        seen.insert({y,i+1});
    }
    cout<<"IMPOSSIBLE";

    return 0;
}
