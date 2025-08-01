#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> cells(n, vector<int>(n, 0));
    int count = 0;

    for (int i=0; i < n; i++) {
        for (int j=0; j<n; j++) {
            char input;
            cin >> input;
            if (input == '.') {
                if (i == 0 || j == 0)
                {
                    cells[i][j] = 1;
                }
                else {
                    cells[i][j] = min(cells[i - 1][j - 1], min(cells[i][j - 1], cells[i - 1][j])) + 1;
                }
            } else {
                cells[i][j] = 0;
            }
            count = count + cells[i][j];
        }
    }

    cout << count << endl;

    return 0;
}