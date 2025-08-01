#include "bits/stdc++.h"
using namespace std;

    
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, b, h, w;
    cin >> n >> b >> h >> w;
    int min = INT_MAX;
    for (int i = 0; i < h; i++) {
        int price;
        cin >> price;
        for (int j = 0; j < w; j++) {
            int beds;
            cin >> beds;
            if (beds >= n) {
                if (min > price*n) {
                    min = price*n;
                }
            }
        }
    }
    if (min == INT_MAX || min > b) {
        cout << "stay home";
    } else {
        cout << min;
    }

    return 0;
}
