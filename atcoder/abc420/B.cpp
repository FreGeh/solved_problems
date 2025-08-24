#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n,m;cin>>n>>m;
    vector<vector<int>> vote(n, vector<int>(m));
    for (int i=0;i<n;i++) {
        string inp;
        cin>>inp;
        for (int j=0;j<m;j++) {
            vote[i][j] = inp[j] - '0';
            //cout << "pasted " << inp[j] << "\n";
        }
    }
    vector<int> points(n);
    for (int i=0;i<m;i++) {
        int choose0 = 0;
        int choose1 = 0;
        for (int j=0;j<n;j++) {
            //cout << "vote counting  " << vote[j][i] << "\n";
            if (vote[j][i]==0) {
                choose0++;
            } else {
                choose1++;
            }
        }
        if (choose0==0 || choose1==0) {
            for (int k=0;k<n;k++) {
                points[k]+=1;
                //cout << "round " << i << " :case 1\n";
            }
        } else if (choose0 < choose1) {
            for (int k=0;k<n;k++) {
                if (vote[k][i]==0) {
                    points[k]+=1;
                    //cout << "round " << i << " :case 2\n";
                }
            }
        } else {
            for (int k=0;k<n;k++) {
                if (vote[k][i]==1) {
                    points[k]+=1;
                    //cout << "round " << i << " :case 3\n";
                }
            }
        }
    }
    int maxim=0;
    for (int k=0;k<n;k++) {
        //cout << points[k] << "\n";
        maxim = max(maxim,points[k]);
    }
    for (int k=0;k<n;k++) {
        if (points[k]==maxim) {
            cout<<k+1 << " ";
        }
    }
    cout << "\n";

    return 0;
}
