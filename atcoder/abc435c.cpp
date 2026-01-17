/**
 *    author:  gemtec
 *    created: 06.12.2025 13:20:17
 *    problem:
**/
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

    int n;cin>>n;
    vector<int> A(n);
    for (auto &a : A) {
        cin>>a;
    }
    int furthest=A[0]-1;
    int sol=0;
    for (int i=0;i<n;i++) {
        furthest=max(furthest,A[i]+i-1);
        debug(furthest);
        if (furthest <= i) {
            break;
        }
        sol++;
    }
    cout<<min(n,sol+1)<<endl; 

    return 0;
}