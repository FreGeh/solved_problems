#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n,p;
    cin >> n >> p;

    int smallest = n;
    int left = 1;
    int right = n;
    while (left <= right) {
        int mid = (left+right)/2;
        cout << "? " << mid << endl;
        int px;
        cin >> px;

        if (px < p) // not enough points
        {
            left = mid +1;
        } else {
            right = mid -1;
            smallest = mid;
        }
    }

    cout << "! " << smallest << endl;

    return 0;
}
