#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    int x;
    cin>>n>>x;
    vector<int> weight(n);
    for (auto &w : weight) cin >> w;
    sort(weight.begin(), weight.end());

    int count=0;
    int i = 0, j=weight.size()-1;
    while (i <= j) {
        if (weight[i]+weight[j] <= x) i++, j--, count++;
        else j--, count++;
    }
    cout << count;

    return 0;
}

// prefer using simple while (i <= j) loop over complicated trying to meet in the middle for loop