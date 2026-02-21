/**
 *      author:  gemtec
 *      created: 21.02.2026 13:03:35
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

    int n;cin>>n;
    int m; cin>>m;
    set<int> chosen;
    for (int i=0;i<n;i++) {
        int l; cin>>l;
        bool found=false;
        for (int j=0;j<l;j++) {
            int juice; cin>>juice;
            if (chosen.count(juice) == 0 && !found) {
                chosen.insert(juice);
                cout<<juice<<"\n";
                found=true;
            }
        }
        if (!found) cout<<0<<"\n";
    }

    return 0;
}