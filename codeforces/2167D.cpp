#include "bits/stdc++.h"
using namespace std;
#define ll long long

// Conditional compilation
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) do { } while(0)
#endif

void solve(vector<ll> &primes) {
    int n;cin>>n;
    vector<ll> nums(n);
    ll all=0;
    for (int i=0;i<n;i++) {
        cin>>nums[i];
        all=gcd(all,nums[i]);
    }
    ll sol=-1;
    if (all==1) {
        sol=2;
    } else {
        for (auto p : primes) {
            if (all % p != 0 || p>all) {
                sol=p;
                break;
            }
        }
    }
    cout<<sol<<"\n";
}

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif
    ll biggest=1000000;
    vector<bool> prime(biggest,true);
    prime[0]=prime[1]=false;
        for (ll i=2;i*i<=biggest;i++) {
            if (prime[i]) {
                for (ll j=i*i;j<=biggest;j+=i) {
                    prime[j]=false;
                }
            }
        }
        vector<ll> primes;
        for (ll i=2;i<=biggest;i++) {
            if (prime[i]) {
                primes.push_back(i);
            }
        }

    int tests; cin >> tests;
    while (tests-- > 0) solve(primes);
    return 0;
}
