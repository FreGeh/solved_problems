#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<char, int>> commands;
    for (int i=0; i<n; i++){
        char op;
        cin >> op;
        int arg;
        cin >> arg;
        commands.push_back({op,arg});
    }

    vector<int> bits (10,2);
    vector<int> flips(10,0);

    for (int b=0;b<10; b++) {
        for (int i = 0; i < n; i++) {
            if (commands[i].first == '|' && (commands[i].second & 1 << b)!=0) {
                bits[b] = 1;
                flips[b]=0;
            }
            if (commands[i].first == '&' && (commands[i].second & 1 << b)==0) {
                bits[b] = 0;
                flips[b]=0;
            }
            if (commands[i].first == '^' && (commands[i].second & 1 << b)!=0) {
                flips[b]++;
            }
        }
    }

    int cand = 1023;
    int cor =0;
    int cxor = 0;

    for (int b=0;b<10; b++ ){
        if (bits[b]==0){
            cand ^= 1<<b;
        }
        if (bits[b]==1){
            cor ^= 1<<b;
        }
        if (flips[b]%2==1){
            cxor ^= 1<<b;
        }
    }

    cout << 3 << endl;
    cout << "| " << cor << endl;
    cout << "& " << cand << endl;
    cout << "^ " << cxor << endl;
    
}
