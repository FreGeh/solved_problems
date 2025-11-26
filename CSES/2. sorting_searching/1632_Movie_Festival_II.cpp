#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n,k; cin>>n>>k;
    vector<pair<int,int>> movies(n);
    for (int i=0; i<n; i++) {
        int a,b; cin>>a>>b;
        movies[i]={b,a};
    }
    sort(movies.begin(), movies.end());
    int sum=0;
    multiset<int> ppl;
    for (int i=0;i<k;i++) ppl.insert(0);
    for (auto mov : movies) {
        auto next = ppl.upper_bound(mov.second); // remember difference between lower and upper bound
        if (next==ppl.begin()) continue;
        ppl.erase(--next); // always remember to decrease by 1
        ppl.insert(mov.first);
        sum++;
    } 
    cout<<sum;
    return 0;
}