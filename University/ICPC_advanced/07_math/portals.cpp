/**
 *      author:  gemtec
 *      created: 27.02.2026 09:38:26
 *      link:https://domjudge.iti.kit.edu/main/team/problems/11/statement
 *      idea: crt
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

ll INF=(ll)4e18;

array<ll,3> gcd_ext(ll a,ll b) {
    if(!a) return {b,0,1};
    auto [d,x1,y1]=gcd_ext(b%a,a);
    return {d,y1-(b/a)*x1,x1};
}

ll norm_mod(ll a,ll mod) {
    a%=mod;
    if(a<0) a+=mod;
    return a;
}

bool crt(ll a, ll m, ll b, ll n, ll &t0, ll &l) {
    auto eg=gcd_ext(m,n);
    ll g=eg[0], x=eg[1];

    if((b-a)%g!=0) return false;

    ll mg=m/g, ng=n/g;
    l=mg*n;

    ll rhs=(b-a)/g;
    ll k=(rhs*x)%ng;
    k=norm_mod(k,ng);

    t0=(a+m*k)%l;
    t0=norm_mod(t0,l);

    return true;
}

struct Edge {
    int to;
    ll t0;
    ll l;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,s,t;
    cin>>n>>m>>s>>t;

    vector<vector<Edge>> g(n);

    for(int i=0;i<m;i++) {
        int a,b;
        ll x,c,y,d;
        cin>>a>>b>>x>>c>>y>>d;

        ll t0,l;
        if(!crt(x,c,y,d,t0,l)) {
            continue;
        }

        g[a].push_back({b,t0,l});
        g[b].push_back({a,t0,l});
    }

    vector<ll> dist(n,INF);

    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    dist[s]=0;
    pq.push({0,s});

    while(!pq.empty()) {
        auto [cur,u]=pq.top();
        pq.pop();

        if(cur!=dist[u]) continue;
        if(u==t) break;

        for(const auto &e:g[u]) {
            ll depart;
            if(cur<=e.t0) {
                depart=e.t0;
            } else {
                ll diff=cur-e.t0;
                ll k=(diff+e.l-1)/e.l;
                depart=e.t0+k*e.l;
            }
            if(depart<dist[e.to]) {
                dist[e.to]=depart;
                pq.push({depart,e.to});
            }
        }
    }

    if(dist[t]>=INF/2) {
        cout<<"impossible\n";
    } else {
        cout<<dist[t]<<"\n";
    }

    return 0;
}