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
    int n,k; cin>>n>>k;
    int a,b,c,d; cin>>a>>b>>c>>d;
    set<int> entries;
    for (int i=1;i<n+1;i++) {
        entries.insert(i);
    }
    entries.erase(a);
    entries.erase(b);
    entries.erase(c);
    entries.erase(d);

    if (k<n+1 || n==4) {
        cout<<-1<<"\n";
    } else {
        cout<<a<<" "<<c<<" ";
        for (auto ent : entries) {
            cout<<ent<<" ";
        }
        cout<<d<<" "<<b<<"\n";
        cout<<c<<" "<<a<<" ";
        for (auto ent : entries) {
            cout<<ent<<" ";
        }
        cout<<b<<" "<<d<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    //int tests; cin >> tests;
    //while (tests-- > 0) solve();
    solve();
}
