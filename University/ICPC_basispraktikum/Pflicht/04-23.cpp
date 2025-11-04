#include "bits/stdc++.h"
using namespace std;
#define ll long long

// Conditional compilation
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) do { } while(0)
#endif

vector<int> X(5);

bool recursive(int pos, int y) {
    if (pos == 5) {
        return y==23;
    }
    int next = X[pos];
    return recursive(pos+1, y + next) || 
         recursive(pos + 1, y - next) ||
         recursive(pos + 1, y * next);
}

void solve() {
    vector<int> a(5);
    for (int &x: a) cin >> x;

    sort(a.begin(), a.end());

    bool possible = false;

    do
    {
        for (int i=0; i<5;i++) {
            X[i]=a[i];
        }
        if (recursive(1, X[0])) {
            possible = true;
            break;
        }
    } while (next_permutation(a.begin(), a.end()));

    cout << (possible ? "Possible" : "Impossible") << endl;
}

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0) solve();

    return 0;
}
