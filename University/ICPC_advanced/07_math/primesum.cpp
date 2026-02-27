/**
 *      author:  gemtec
 *      created: 26.02.2026 15:24:39
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

int MOD=1000000007;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    
    int n;cin>>n;
    vector<bool> is(n+1,true);
    if(n>=0) is[0]=false;
    if(n>=1) is[1]=false;

    for(int i=2;i*i<=n;i++){
        if(!is[i]) continue;
        for(int j=i*i;j<=n;j+=i) is[j]=false;
    }

    vector<int> primes;
    for(int i=2;i<=n;i++){
        if(is[i]){
            primes.push_back(i);
        }
    }

    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int p:primes){
        for(int s=p; s<=n; s++){
            int v=dp[s]+dp[s-p];
            if(v>=MOD) v-=MOD;
            dp[s]=v;
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}