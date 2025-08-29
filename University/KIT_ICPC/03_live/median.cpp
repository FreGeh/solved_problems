#include "bits/stdc++.h"
using namespace std;

struct objectx
{
    int id;

    bool operator<(const objectx &o) const
    {
        cout << "? " << o.id << " " << id << endl;
        string response;
        cin >> response;
        if (response == "lighter") {
            return true; //b weighs more
        } else {
            return false; // a weighs more
        }
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<objectx> objects(n);

    for (int i=1; i < n+1; i++) {
        objects[i-1] = objectx({i});
    }

    sort(objects.begin(), objects.end());

    cout << "! " << objects[(n/2)].id << endl;

    return 0;
}