#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n; cin>>n;
    vector<pair<int,int>> movies(n);
    for (int i=0; i<n; i++) {
        int a,b; cin>>a>>b;
        movies[i]={b,a};
    }
    sort(movies.begin(), movies.end());
    int cur=0;
    int sum=0;
    for (auto mov : movies) {
        if (mov.second >= cur) {
            cur=mov.first;
            sum++;
        }
    } 
    cout<<sum;
    return 0;
}