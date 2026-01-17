#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N,M; cin>>N>>M;
    string S,T; cin>>S>>T;
    // vector<int> cum(N + 1, 0);
    vector<uint8_t> flip(N + 1, 0);

    for (int i=0; i<M;i++) {
        int l,r; cin>>l>>r;
        l--; r--;
        // cum[l] += 1; 
        // cum[r] += 1; 
        flip[l] ^= 1;
        flip[r+1] ^= 1;
    }

    uint8_t cur = 0;

    for (int i=0; i<N; i++) {
        cur ^= flip[i];
        cout << (cur ? T[i] : S[i]);
        // cum[i+1] += cum[i];
    }
    /* 
    for (int i=0; i<N; i++) {
        if (cum[i]%2 == 0) {
            cout << S[i];
        } else {
            cout << T[i];
        }
    }
    */
    return 0;
}
/* --- learnings ---
- mark interval boundaries somehow (parity)
- either with XOR or just simple int
- then loop over all digits and save in cur temp value in how many intervals we are currently
- alternatively just add all intervals in i-1 to i and determine with mod 2 which char to print
*/