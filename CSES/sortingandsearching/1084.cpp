#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> applicants(n), apartments(m);

    for (ll i=0;i<n;i++) { 
        cin >> applicants[i];
    }
    for (ll i=0;i<m;i++) { 
        cin >> apartments[i];
    }
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());
    ll count = 0;
    for (ll i=0,j=0;i<n && j<m;) {
        if (abs(applicants[i]-apartments[j])<=k) {
            j++;
            i++;
            count++;
        } else if (applicants[i]>apartments[j]+k) {
            j++;
        } else {
            i++;
        }
    }
    cout << count;


    return 0;
}

// dont think too hard and just implement the simple math equation and then make sure you read the task description with all variables properly
// also learnt new for loop structure that works like while loop just cleaner i guess