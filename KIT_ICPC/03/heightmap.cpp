#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<int, int> map;
    for (int i=0; i<(2*n)-1; i++) {
        for (int j=0; j<n;j++) {
            int var;
            cin >> var;
            map[var]++;
        }
    }

    vector<int> result;
    for (const auto &pair : map)
    {
        if (pair.second % 2 == 1) {
            result.push_back(pair.first);
        }
    }
    for (const auto &output : result)
    {
        cout << output << " ";
    }

    return 0;
}