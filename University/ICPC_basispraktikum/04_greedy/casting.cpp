#include "bits/stdc++.h"
using namespace std;
#define ll long long

// Conditional compilation
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) do { } while(0)
#endif

void solve() {
    int n;
    cin >> n;
    cin.ignore();
    vector<bool> N(n);

    char c;
    int counter =0;
    while (cin.get(c))
    {
        if (c == '\n')
        {
            break;
        }
        else
        {
            if (c == 'B') {
                N[counter] = false;
            } else{
                N[counter] = true;
            }
        }
        counter++;
    }

    vector<int> spells;

    for (int i=0; i<n -1; i++)
    {   
        if (!N[i]) {
            spells.push_back(i);
            N[i] = true;
            N[i+1] = !N[i+1];
        }
    }

    bool outcome = false;
    if (!N[n-1]) //letzte ist schwarz
    {
        if (n%2 == 1) {
            for (int i = 0; i < n - 1; i = i + 2) // alle vorherigen auch auf schwarz
            {
                spells.push_back(i);
            }
            if (!N[n - 1]) {
                outcome = true;
            }
        }
    } else {
        outcome = true;
    }
    if (outcome) {
        cout << "YES" << endl;
        cout << spells.size() << endl;
        for (int spell : spells)
        {
            cout << spell+1 << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
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
