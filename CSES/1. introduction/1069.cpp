#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    string s;
    cin>>s;
    char curr = 'Z';
    int maxi=1, cur=1;
    for (char c : s) {
        if (c==curr) {
            cur++;
            maxi = max(cur,maxi);
        } else {
            cur = 1;
        }
        curr = c;
    }
    cout << maxi;

    return 0;
}
