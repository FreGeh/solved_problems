#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cols, rows;
    cin >> cols >> rows;
    vector<vector<int>> cells(rows, vector<int>(cols));

    for (int i = 0; i < rows; ++i)
    {
        string row;
        cin >> row;
        for (int j = 0; j < cols; ++j)
            cells[i][j] = (row[j] == '.' ? 1 : 0);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (cells[i][j] == 0) {
                continue;
            } else
                if (i == 0 && j == 0)
                {
                    cells[i][j] = 1;
                }
                else if (i != 0 && j == 0)
                {
                    cells[i][j] = cells[i - 1][j] % (1000000000 + 7);
                }
                else if (i == 0 && j != 0)
                {
                    cells[i][j] = cells[i][j - 1] % (1000000000 + 7);
                }
                else if (cells[i - 1][j] == 0 && cells[i][j - 1] == 0)
                {
                    cells[i][j] = 0;
                }
                else if (cells[i - 1][j] != 0 && cells[i][j - 1] == 0)
                {
                    cells[i][j] = cells[i - 1][j] % (1000000000 + 7);
                }
                else if (cells[i - 1][j] == 0 && cells[i][j - 1] != 0)
                {
                    cells[i][j] = cells[i][j - 1] % (1000000000 + 7);
                }
                else if (cells[i - 1][j] != 0 && cells[i][j - 1] != 0)
                {
                    cells[i][j] = (cells[i - 1][j] + cells[i][j - 1]) % (1000000000 + 7);
                }
        }
    }
    cout << cells[rows-1][cols-1]%(1000000000+7) << endl;

    return 0;
}
