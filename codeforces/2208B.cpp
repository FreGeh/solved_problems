/**
 *      author:  gemtec
 *      created: 14.03.2026 15:42:59
 *      link:
 *      idea:
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long



void solve() {
    int n,k,p,m; cin>>n>>k>>p>>m;
    vector<pair<int,int>> cards(n+1);
    for (int i=1;i<=n;i++) {
        int c; cin>>c;
        cards[i]={c,i};
    }
    pair<int,int> goal=cards[p];
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // min queue
    for (int i=1;i<=k;i++) {
        if (cards[i] == goal) continue;
        pq.push(cards[i]);
    }
    queue<pair<int,int>> back;
    for (int i=k+1; i<=n;i++) {
        if (cards[i] == goal) continue;
        back.push(cards[i]);
    }
    int counter=0;
    while (m-goal.first>=0) {
        if (p>k) {
            if (pq.empty()) break;
            pair<int,int> t = pq.top();
            pq.pop();
            back.push(t);
            m-=t.first;
            p--;
            if (p > k && !back.empty()) {
                pair<int,int> neww = back.front();
                back.pop();
                pq.push(neww);
            }
        }
        else {
            if (m-goal.first>=0) {
                m-=goal.first;
                counter++;
                p=n;
                if (p > k && !back.empty()) {
                    pair<int,int> neww = back.front();
                    back.pop();
                    pq.push(neww);
                }
            } else {
                break;
            }
        }
    }
    cout<<counter<<"\n";
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