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
    int n,m;cin>>n>>m;
    int sum=0;
    int lasta=0,lastb=0;
    for (int i=0;i<n;i++) {
        int a,b;cin>>a>>b;
        int time = a-lasta;
        if (lastb==b) sum+= (time/2)*2;
        else sum+= (time&1)?time:time-1;
        lasta=a;
        lastb=b;
    }
    sum+=m-lasta;

    cout<<sum<<"\n";
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
