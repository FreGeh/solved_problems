#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n,q;cin>>n>>q;
    vector<int> A(n),B(n);
    for (auto &a : A) {
        cin>>a;
    }
    for (auto &b : B) {
        cin>>b;
    }
    ll sum =0;
    for (int i=0;i<n;i++) {
        //cout << "the minimum of " << A[i] << " and " << B[i] << " is "<< min(A[i],B[i])<< "\n";
        sum+=min(A[i],B[i]);
    }
    for (int i=0;i<q;i++) {
        char type; cin>>type;
        int x,y;cin>>x>>y;
        //cout << " query " << type << " with " << x << " and " << y << "\n";
        sum-=min(A[x-1],B[x-1]);
        if (type=='A') {
            A[x-1]=y;
        } else {
            B[x-1]=y;
        }
        sum+=min(A[x-1],B[x-1]);
        cout << sum << "\n";
    }

    return 0;
}
