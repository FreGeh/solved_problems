#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin>>n;
    vector<pair<int,bool>> I;
    for (int i=0;i<n;i++) {
        int a,b; cin>>a>>b;
        I.push_back({a, true});
        I.push_back({b, false});
    }
    sort(I.begin(), I.end());

    int cur=0;
    int best=0;
    for (auto i : I) {
        if (i.second) cur++;
        else cur--;
        best=max(best,cur);
    }
    cout << best;

    return 0;
}
