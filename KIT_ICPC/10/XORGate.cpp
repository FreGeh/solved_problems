#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;

    const unsigned int base = 1u << 19;

    for (int i=0;i<n;i++) {
        cout << base + i << " ";
    }
    return 0;
}
