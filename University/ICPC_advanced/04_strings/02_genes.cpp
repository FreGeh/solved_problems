/**
 *      author:  gemtec
 *      created: 19.01.2026 11:02:34
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

int get_id(char c) {
    if (c == 'A') return 0;
    if (c == 'C') return 1;
    if (c == 'G') return 2;
    return 3;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    int n,k,q; cin>>n>>k>>q;
    uint64_t B = (rng()%5000)*2 + 13337;

    vector<uint64_t> P(k+1);
    P[0] = 1;
    for (int i=1; i<=k; i++) {
        P[i]=P[i-1]*B;
    }

    auto get_hash = [&](const string& s) {
        uint64_t h = 0;
        for (char c : s) h = h*B+get_id(c);
        return h;
    };

    vector<uint64_t> db(n);
    for (int i=0; i<n; i++) {
        string s; cin>>s;
        db.push_back(get_hash(s));
    }
    sort(db.begin(), db.end());
    db.erase(unique(db.begin(), db.end()), db.end());

    int ans = 0;

    for (int i=0; i<q; i++) {
        string s; cin>>s;
        uint64_t h=get_hash(s);
        bool found = binary_search(db.begin(),db.end(),h);

        if (!found) {
            for (int i=0; i<k; i++) {
                int c = get_id(s[i]);
                uint64_t val = P[k-1-i];
                uint64_t base = h-c*val;

                for (int v=0; v<4; v++) {
                    if (v==c) continue;
                    if (binary_search(db.begin(), db.end(), base+v*val)) {
                        found=true;
                        break;
                    }
                }
                if (found) break;
            }
        }
        if (found) ans++;
    }
    cout<<ans<<"\n";

    return 0;
}