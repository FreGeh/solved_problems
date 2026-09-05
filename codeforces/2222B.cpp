/**
 *      author:  gemtec
 *      created: 25.04.2026 16:49:14
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

void solve() {
  int n,m; cin>>n>>m;
  vector<ll> A(n);
  vector<ll> Aodd;
  vector<ll> Aeven;
  vector<ll> X(m);
  ll Xodd = 0;
  ll Xeven = 0;
  ll sum = 0;
  for (auto &a : A) {
    cin>>a;
    sum+=a;
  }
  for (auto &x : X) {
    cin>>x;
    x--;
  }
  for (int i=0;i<n;i++) {
    ll a = A[i];
    if (i%2==0) Aodd.push_back(a);
    else Aeven.push_back(a);
  }
  for (int i=0;i<m;i++) {
    ll x = X[i];
    if (x%2==0) Xodd++;
    else Xeven++;
  }
  sort(Aeven.begin(), Aeven.end(), greater<ll>());
  for (int i=0; i<Xeven; i++) {
    if (Aeven.size()>i && (Aeven[i]>0 || i==0)) sum -= Aeven[i];
  }
  sort(Aodd.begin(), Aodd.end(), greater<ll>());
  for (int i=0; i<Xodd; i++) {
    if (Aodd.size()>i && (Aodd[i]>0 || i==0)) sum -= Aodd[i];
  }
  cout<<sum<<endl;
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