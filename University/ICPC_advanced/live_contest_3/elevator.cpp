/**
 *      author:  gemtec
 *      created: 03.03.2026 15:34:41
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

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int needed = 0;
    while (m >n) {
        if (m%2 == 0) {
            m/= 2;
        } else {
            m++;
        }
        needed++;
    }
    needed+=(n-m);
    cout <<needed<<"\n";
    return 0;
}