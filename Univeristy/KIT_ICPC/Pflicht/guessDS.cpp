#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "? " << "insert " << 15 << endl;
    cout << "? " << "insert " << 10 << endl;
    cout << "? " << "insert " << 10 << endl;
    cout << "? " << "insert " << 30 << endl;
    cout << "? " << "insert " << 20 << endl;

    cout << "? " << "remove" << endl;
    int response;
    cin >> response;

    //queue - 15
    if (response == 15) {
        cout << "! queue" << endl;
        return 0;
    }

    //stack - 20
    if (response == 20) {
        cout << "! stack" << endl;
        return 0;
    }

    cout << "? " << "remove" << endl;
    int response2;
    cin >> response2;
    
    //set - 10 - 15
    if (response==10 && response2 == 15) {
        cout << "! set" << endl;
        return 0;
    }

    //priority queue - 10 - 10
    if (response==10 && response2 == 10) {
        cout << "! pq" << endl;
        return 0;
    }

    return 0;
}