#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    string s; cin>>s;
    if (s == "red") {
        cout << "SSS";
    } else if (s == "green") {
        cout << "MMM";
    } else if (s == "blue") {
        cout << "FFF";
    } else {
        cout << "Unknown";
    }
    return 0;
}
