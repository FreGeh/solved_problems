/**
 *      author:  gemtec
 *      created: 16.03.2026 12:00:50
 *      link:
 *      idea:
*/
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

    int n,k; cin>>n>>k;
    vector<int> res(n+1);
    for (int i=1; i<=n; i++) {
        cin>>res[i];
    }
    for (int i=1; i<=n; i++) {
        if (i%k == 0) cout<<res[i]<<" ";
    }

    return 0;
}