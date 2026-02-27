/**
 *      author:  gemtec
 *      created: 27.02.2026 12:36:32
 *      link:https://domjudge.iti.kit.edu/main/team/problems/10/statement
 *      idea:pew
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

ll gcd_ext(ll a, ll b, ll& x, ll& y) {
    if(!b) { x=1; y=0; return a; }
    ll x1, y1;
    ll d= gcd_ext(b, a%b, x1, y1);
    x=y1; y=x1-y1*(a/b);
    return d;
}

pair<ll, ll> crt(ll r1, ll m1, ll r2, ll m2) {
    ll x, y;
    ll g=gcd_ext(m1, m2, x, y);
    if((r2-r1)%g != 0) return {-1, -1};
    ll l =(m1/g)*m2;
    ll k=(r2-r1)/g;
    ll mod_k=m2/g;
    k = (k%mod_k + mod_k)%mod_k;
    x = (x%mod_k + mod_k)%mod_k;
    ll mul = (ll)(k * x % mod_k);
    ll ans =(r1 + mul * m1) % l;
    return {(ans+l)%l, l};
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll a, b, c; int n;
    while(cin >> a >> b >> c >> n) {
        vector<array<ll, 3>> p(n+1);
        for(int i=0; i<=n; i++) cin >> p[i][0] >> p[i][1] >> p[i][2];

        ll min_t = -1;
        int hit = -1;
        ll mod_sys[] = {2*a, 2*b, 2*c};

        for(int i=0; i<=n; i++) {
            for(int sx : {1, -1}) {
                for(int sy : {1, -1}) {
                    for(int sz : {1, -1}) {
                        ll r1 = (sx * p[i][0]- p[0][0]) % mod_sys[0];
                        pair<ll, ll> res = {(r1 + mod_sys[0]) % mod_sys[0], mod_sys[0]};

                        ll r2 = (sy * p[i][1] - p[0][1]) % mod_sys[1];
                        res = crt(res.first, res.second, (r2 + mod_sys[1]) % mod_sys[1], mod_sys[1]);
                        if(res.first == -1) continue;

                        ll r3 = (sz * p[i][2] - p[0][2]) % mod_sys[2];
                        res = crt(res.first, res.second, (r3 + mod_sys[2]) % mod_sys[2], mod_sys[2]);
                        if(res.first == -1) continue;

                        ll t = res.first;
                        if(t == 0) t += res.second;

                        if(min_t == -1 || t<min_t) {
                            min_t = t;
                            hit = i;
                        }
                    }
                }
            }
        }

        if(min_t == -1) cout<<"nothing hit\n";
        else cout<<hit<< "\n";
    }
    return 0;
}