#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string s; cin>>s;
    int counter=0;
    int n=s.length();
    string temp, output;
    for (int i=0;i<n;i++) {
        temp+=s[i];
        if (s[i]== '.') {
            counter=i+1;
            break;
        }
    }
    if (counter>9 || counter<2) {
        cout<<"NO\n";
        return 0;
    }
    //bool firstdot=true;
    int length=0;
    output.append(temp);
    temp.clear();
    for (int i=counter;i<n;i++) {
        temp+=s[i];
        length++;
        //cout<<"cur length "<<length<<" current temp "<<temp<<" current string "<<output<<"\n";
        if (s[i]=='.') {
            if (length>12 || length<3) {
                cout<<"NO\n";
                return 0;
            } else {
                int mid=0;
                //cout<<length<<"\n";
                mid = min(3,(length)/2);
                //cout<<"appending "<<mid<<" up to "<<temp.size()<<"\n";
                output.append(temp, 0, mid);
                output.append("\n");
                output.append(temp, mid, temp.size());
                counter=0;
                temp.clear();
                length=0;
            }
        }
    }
    //cout<<"after finishing loop cur length "<<length<<" current temp "<<temp<<" current string "<<output<<"\n";
    if (length>3 || length<1) {
        cout<<"NO\n";
        return 0;
    }
    output.append(temp);
    cout<<"YES\n";
    cout<<output;

    return 0;
}
