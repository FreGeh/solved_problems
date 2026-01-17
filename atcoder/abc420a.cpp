#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int x,y;cin>>x>>y;
    y=y%12;
    if ((x+y)%12 == 0) {
        cout << 12;
    } else {
        cout<<(x+y)%12;
    }

    return 0;
}
