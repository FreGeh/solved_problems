#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vector<ll> M(N);
    for (ll &x : M)
    {
        cin >> x;
    }
    if (N == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if (N == 1)
    {
        cout << M[0] << endl;
        return 0;
    }
    vector<ll> sol(N);
    sol[0]=M[0];
    sol[1] = max(M[0],M[1]);
    for (ll i = 2; i < N; ++i) {
        sol[i] = max(sol[i-1], sol[i-2]+M[i]);
    }
    cout << sol[N-1];

    return 0;
}
