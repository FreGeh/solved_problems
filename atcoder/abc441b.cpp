/**
 *      author:  gemtec
 *      created: 17.01.2026 13:02:51
 *      link:
 *      idea:
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,m;cin>>n>>m;
    string s,t; cin>>s>>t;
    int q; cin>>q;

    unordered_set<char> s_, t_;
    for (char c : s) {
        s_.insert(c);
    }
    for (char c : t) {
        t_.insert(c);
    }
    for (int i=0;i<q;i++) {
        string w; cin>>w;
        bool s_d = true;
        bool t_d = true;
        bool known = true;
        for (char c : w) {
            if (!t_.count(c) && s_.count(c)) {
                t_d = false;
                if (!s_d) {
                    known=false;
                    break;
                }
            }
            else if (t_.count(c) && !s_.count(c)) {
                s_d = false;
                if (!t_d) {
                    known=false;
                    break;
                }
            }
        }
        if (!known || (s_d && t_d)) cout<<"Unknown\n";
        else if (s_d && known) cout<<"Takahashi\n";
        else if (t_d && known) cout<<"Aoki\n";
    }

    return 0;
}