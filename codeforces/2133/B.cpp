#include "bits/stdc++.h"
using namespace std;
#define ll long long

// Conditional compilation
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) do { } while(0)
#endif

void solve() {
    int n; cin >> n;
    priority_queue<ll> q;
    for (int i = 0; i < n; i++) {
        ll grump;
        cin >> grump;
        q.push(grump);
    }
    ll emeralds =0;
    while (q.size() > 1) {
        auto g = q.top(); q.pop();
        auto h = q.top(); q.pop();
        int c=max(g,h);
        emeralds+=c;
        int a=g-min(g,h);
        int b=h-min(g,h);
        if (a>=b) {
            q.push(b);
        } else {
            q.push(a);
        }
    }
    cout << emeralds << "\n";
}

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0) solve();

    return 0;
}
