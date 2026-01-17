/**
 *    author:  gemtec
 *    created: 06.12.2025 13:00:28
 *    problem:
**/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;cin>>n;
    ll sum=0;
    for (int i=1;i<=n;i++) {
        sum+=i;
    }
    cout<<sum<<endl;

    return 0;
}