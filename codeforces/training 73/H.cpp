#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int a, b, c;
    int m;
    cin >> a >> b >> c >> m;

    vector<vector<int>> in(m, vector<int> (2,0));

    for (int i=0; i< m;  i++) {
        int co;
        cin >> co;
        string t;
        cin >> t;
        int type = t=="PS/2";
        in[i] = {co, type};
    }
    
    sort(in.begin(), in.end());

    int cost = 0;
    int sat = 0;

    for (int i=0; i< m; i++) {
        if (in[i][1] == 0 && a > 0) {
            cost += in[i][0];
            sat++;
            a--;
        } else if (in[i][1] == 1 && b > 0) {
            cost +=  in[i][0];
            sat++;
            b--;
        } else if (c > 0) {
            cost += in[i][0];
            sat++;
            c--;
        }
    }

    cout << sat << " " << cost  << endl;
}
