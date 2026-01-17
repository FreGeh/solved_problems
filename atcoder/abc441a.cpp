/**
 *      author:  gemtec
 *      created: 17.01.2026 13:00:18
 *      link: https://atcoder.jp/contests/abc441/tasks/abc441_a
 *      idea:
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int p,q; cin>>p>>q;
    int x,y; cin>>x>>y;
    if ((x-p)<100 && (x-p)>=0 && (y-q)<100 && (y-q)>=0) {
        cout<<"Yes\n";
    } else {
        cout<<"No\n";
    }

    return 0;
}