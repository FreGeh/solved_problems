#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n,x;
    cin>>n>>x;
    map<ll, int> seen;
    ll output=0;
    ll cur=0;
    seen[0]=1;
    for (int i=0;i<n;i++) {
        int a;
        cin>>a;
        cur+=a;
        output+=seen[cur-x]; 
        // if negative numbers or 0 is allowed, the same sum can occur multiple times then
        seen[cur]++;
    }

    cout<<output<<"\n";

    return 0;
}
