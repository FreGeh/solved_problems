#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long tests;
    cin >> tests;

    for (int i = 0; i < tests; i++)
    {
        long long num;
        cin >> num;

        cout << static_cast<long long>(sqrt((long double)num)) << endl;
    }

    return 0;
}