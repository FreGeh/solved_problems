#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> m(367, vector<int> (2,0));
    for (int i=0; i<n; i++) {
        char p;
        cin >> p;
        int c = p=='M';
        int a, b;
        cin >> a>> b;
        for (int i=a; i<= b; i++) {
            m[i][c]++; 
        }
    }
    int maxi = 0;
    for (int i=1; i<=366; i++) {
        maxi = max(maxi, min(m[i][0],m[i][1]));
    }
    cout << maxi*2;
    return 0;
}
