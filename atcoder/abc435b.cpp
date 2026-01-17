/**
 *    author:  gemtec
 *    created: 06.12.2025 13:02:25
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
    vector<int> A(n+1);
    vector<ll> pre(n+1,0);
    for (int i=1; i<=n;i++) {
        cin>>A[i];
    }
    for (int i=1; i<=n;i++) {
        pre[i]=pre[i-1]+A[i];
    }
    int sol=0;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<=n;j++) {
            debug(i,j);
            bool cond=true;
            for (int m=i+1;m<=j;m++) {
                debug(m,A[m]);
                debug(pre[j],pre[i], pre[j]-pre[i] % A[m]);
                if ((pre[j]-pre[i]) % A[m]==0) {
                    cond=false;
                    break;
                }
            }
            debug(cond);
            if (cond) sol++;
        }
    }

    cout<<sol<<endl;

    return 0;
}