#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<int> difficulty(n);
    for (int i=0; i < n; i++) {
        cin >> difficulty[i];
    }

    sort(begin(difficulty), end(difficulty));

    vector<int> uniqueDifficulty = difficulty;
    uniqueDifficulty.erase(unique(uniqueDifficulty.begin(), uniqueDifficulty.end()), uniqueDifficulty.end());

    for (int i=0; i < m; i++) {
        int l,r;
        cin >> l >> r;

        auto it_l = lower_bound(difficulty.begin(), difficulty.end(), l);
        auto it_r = upper_bound(difficulty.begin(), difficulty.end(), r);

        long long total = it_r - it_l; 

        auto it_u_l = lower_bound(uniqueDifficulty.begin(), uniqueDifficulty.end(), l);
        auto it_u_r = upper_bound(uniqueDifficulty.begin(), uniqueDifficulty.end(), r);

        long long differentProblems = it_u_r - it_u_l; 

        int hardest = -1;

        auto hardest_it = upper_bound(difficulty.begin(), difficulty.end(), r);

        if (it_l != it_r) {
            auto actual_it = it_r;
            --actual_it;
            if (*actual_it >= l) {
                hardest = *actual_it;
            }
        }

        cout << total << " " << differentProblems << " " <<  hardest << "\n";
    }

    return 0;
}