/**
 *    author:  gemtec
 *    created: 28.11.2025 17:20:19
 *    problem:
**/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin>>n;
    vector<pair<string,string>> names(n);
    string s;
    getline(cin,s);
    for (int i=0;i<n;i++) {
        getline(cin,names[i].second);
        //cerr<<" got "<<names[i].second<<endl;
        int counter=0;
        for (auto &c:names[i].second) {
            counter++;
            if ((c>='A')&&(c<='Z')) {
                names[i].first=names[i].second.substr(counter-1, names[i].second.length());
                //cout<<names[i].first<<endl;
                break;
            }
        }
    }
    sort(names.begin(), names.end());
    for (int i=0;i<n;i++) {
        cout<<names[i].second<<endl;
    }


    return 0;
}