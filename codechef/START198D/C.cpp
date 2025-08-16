#include "bits/stdc++.h"
using namespace std;
#define ll long long

// Conditional compilation
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) do { } while(0)
#endif

int solve() {
    int gold, silv, gold_targ, silv_targ; 
    cin >> gold>>silv>>gold_targ>>silv_targ;
    int gold_delta = gold-gold_targ;
    int silv_delta = silv-silv_targ;
    if (gold_targ > gold+(silv/5) || silv_targ > silv+(gold*5)) {
        cout << "No\n";
        return 0;
    } else {
            int delta = (silv_delta + (gold_delta*5));
            if (delta >= 0) {
                int gold_cnt = 0;
                while (delta >= 0) {
                    if (delta == gold_cnt) {
                        cout << "Yes\n";
                        return 0;
                    }
                    delta = delta - 5;
                    gold_cnt++;
                }
                cout << "No\n";
                return 0;
            }
            else {
                cout << "No\n";
                return 0;
            }
    }
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
