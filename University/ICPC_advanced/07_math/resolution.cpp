/**
 *      author:  gemtec
 *      created: 25.02.2026 11:15:42
 *      link: https://domjudge.iti.kit.edu/main/team/problems/13/statement
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

ll power(ll a, ll b, ll m) {
    ll res=1;
    a%=m;
    while(b>0) {
        if(b&1) res=((__int128)res*a)%m;
        a=((__int128)a*a)%m;
        b>>=1;
    }
    return res;
}

bool is_prime(ll n) {
    if(n<2) return false;
    if(n==2 || n==3) return true;
    if(n%2==0) return false;
    ll d=n-1;
    int s=0;
    while(d%2==0) {
        d/=2;
        s++;
    }
    static vector<ll> w={2,3,5,7,11,13,17,19,23,29,31,37};
    for(ll a: w) {
        if(n<=a) break;
        ll x=power(a,d,n);
        if(x==1 || x==n-1) continue;
        bool comp=true;
        for(int r=1; r<s; r++) {
            x=(ll)((__int128)x * x % n);
            if(x==n-1) {
                comp=false;
                break;
            }
        }
        if(comp) return false;
    }
    return true;
}

ll rho(ll n) {
    if(n%2==0) return 2;
    ll x=2, y=2, d=1, c=1;
    auto f=[&](ll x){ return (ll)(((__int128)x * x + c) % n); };
    while(d==1) {
        x=f(x);
        y=f(f(y));
        d=gcd(abs(x-y), n);
        if(d==n) {
            x=rand()%(n-2)+2;
            y=x;
            c=rand()%(n-1)+1;
            d=1;
        }
    }
    return d;
}

void factor(ll n, vector<ll>& v) {
    if(n==1) return;
    if(is_prime(n)) {
        v.push_back(n);
        return;
    }
    ll d=rho(n);
    factor(d, v);
    factor(n/d, v);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n; cin>>n;
        vector<ll> v;
        factor(n, v);
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
        cout<<"\n";
    }
    return 0;
}