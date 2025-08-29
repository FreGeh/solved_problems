// https://usaco.org/index.php?page=viewproblem2&cpid=572
#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n,q;cin>>n>>q;
    vector<int> ho(n+1,0),gu(n+1,0),je(n+1,0);
    for (int i=1;i<n+1;i++) {
        ho[i]=ho[i-1];
        gu[i]=gu[i-1];
        je[i]=je[i-1];
        int breed;cin>>breed;
        if (breed==1) ho[i]++;
        else if (breed==2) gu[i]++;
        else if (breed==3) je[i]++;
    }
    for (int i=0;i<q;i++) {
        int a,b;cin>>a>>b;
        cout << ho[b]-ho[a-1] << " " << gu[b]-gu[a-1] << " " << je[b]-je[a-1] << "\n";
    }

    return 0;
}
