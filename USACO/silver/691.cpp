// https://usaco.org/index.php?page=viewproblem2&cpid=691
#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n;cin>>n;
    vector<int> hoof(n+1,0),paper(n+1,0),scissor(n+1,0);
    for (int i=1;i<=n;i++) {
        hoof[i]=hoof[i-1];
        paper[i]=paper[i-1];
        scissor[i]=scissor[i-1];

        char inp; cin>>inp;
        if (inp=='H') paper[i]++;
        else if (inp=='P') scissor[i]++;
        else if (inp=='S') hoof[i]++;
    }
    int res=0;
    for (int i=1;i<=n;i++) {
        int before = max(scissor[i], max(paper[i],hoof[i]));
        int after = max(paper[n]-paper[i], max(scissor[n]-scissor[i], hoof[n]-hoof[i]));
        res = max(res,before+after);
    }

    cout<<res;

    return 0;
}

// learning: dont forget sizing vectors correctly (n+1) 