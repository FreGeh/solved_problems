#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int Q; cin >> Q;
    vector<int> bag;
    for (int i=0;i<Q;i++) {
        int query; cin>>query;
        if (query == 1) {
            int numb; cin>>numb;
            bag.push_back(numb);
        } else {
            sort(bag.begin(), bag.end());
            auto place =lower_bound(bag.begin(), bag.end(), 0);
            cout << *place << "\n";
            bag.erase(place);
        }
    }
    return 0;
}
