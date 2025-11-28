#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,t;cin>>n>>t;
    vector<int> A(n);
    for (auto &x:A) cin>>x;

    int r=0, ans=0, sum=0;
    for (int l=0;l<n;l++) {
        while (r<n && sum+A[r]<=t) sum+=A[r++]; // increase window until not possible
        ans=max(ans,r-l); // tracking best possible size of window
        if (l==r) r++; // keep going
        else sum-=A[l]; // removing left element
    }
    cout<<ans<<endl;

    return 0;
}
