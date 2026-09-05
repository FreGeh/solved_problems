#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin>>n;
    map<int,int> paintings;
    for (int i=0;i<n;i++) {
        int x; cin>>x;
        paintings[x]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto entry : paintings) {
        pq.push(entry.second);
    }
    ll sol=0, reduce=0;
    while (!pq.empty() && reduce<n) {
        int smallest=pq.top()-reduce;
        int siz=pq.size()-1;
        pq.pop();
        sol+=smallest*siz;
        reduce += smallest;
    }
    cout<<sol<<"\n";
}
