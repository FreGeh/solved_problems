#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        for (int i=0; i < k; i++) {
            string falseword;
            cin >> falseword;
        }
        char falsespace;
        cin.get(falsespace);
        char c;
        while (cin.get(c))
        {
            if (c == '\n')
            {
                cout << endl;
                break;
            }
            else
            {
                cout << c;
            }   
        }
    }
    cout << endl;
    return 0;
}