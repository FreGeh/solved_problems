/**
 *      author:  gemtec
 *      created: 21.02.2026 13:16:43
 *      link:
 *      idea: 
 *      learning: in future just do the straightforward idea and dont overcomplicate
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

void solve() {
    int n,d; cin>>n>>d;
    vector<int> buy(n),use(n);
    for (int i=0; i<n;i++) {
        cin>>buy[i];
    }
    for (int i=0; i<n;i++) {
        cin>>use[i];
    }
    queue<pair<int,int>> q;
    for (int i=0;i<n;i++) {
        q.push({i+d, buy[i]});
        int k=use[i];
        while (k>0 && !q.empty()) {
            auto &p = q.front();
            if (k<p.second) {
                p.second-=k;
                k=0;
            } else {
                k-=p.second;
                q.pop();
            }
        }

        while (!q.empty() && q.front().first <= i) q.pop();
    }
    ll cur=0;
    while (!q.empty()) {
        cur+=q.front().second;
        q.pop();
    }

    cout<<cur<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    int tests; cin >> tests;
    while (tests-- > 0) solve();
    return 0;
}