/**
 *    author:  gemtec
 *    created: 03.12.2025 22:26:40
 *    problem: https://domjudge.iti.kit.edu/main/team/problems/50/statement
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

    int n; cin>>n;
    vector<int> A(n);
    for (int i=0; i<n; i++) {
        cin>>A[i];
    }

    vector<int> B = A;
    sort(B.begin(), B.end());

    auto costs = [&](ll l) -> ll {
        return l*l + 5*l + 2;
    };

    map<int, int> occ;
    ll total_diff=0;
    auto update = [&](int id, int change){
        int cur=occ[id];
        int aft=cur+change;
        if (cur!=0 && aft==0)total_diff--;
        else if (cur==0 && aft!=0) total_diff++;
        occ[id]=aft;
    };

    ll ans=0;
    int j=0;
    bool found=false;
    for (int i=0;i<n;i++) {
        if (i>j && A[i-1]>A[i]) found=true;
        update(A[i],+1);
        debug(A[i],occ[A[i]]);
        update(B[i],-1);
        debug(B[i],occ[B[i]]);
        if (total_diff==0) {
            if (found) ans+=costs(i-j+1);
            found=false;
            j=i+1;
        }
    }
    cout<<ans<<endl;

    return 0;
}
// 16
// 26
// 38
// 52
// 68