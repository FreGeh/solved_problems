#include <bits/stdc++.h>
using namespace std;

int main() {
    set<char> input;
    for (int i=0;i<3;i++) {
        char x; cin>>x;
        input.insert(x);
    }
    string answer = (input.count('c') && input.count('a') && input.count('t'))? "YES":"NO";
    cout << answer;
    return 0;
}
