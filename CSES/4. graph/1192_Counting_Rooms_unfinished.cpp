/**
 *    author:  gemtec
 *    created: 01.12.2025 22:39:11
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

    int n,m;cin>>n>>m;
    vector<vector<bool>> A(n, vector<bool>(m));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            char c; cin>>c;
            if (c=='#') {
                A[i][j]=false;
            } else {
                A[i][j]=true;
            }
        }
    }

    int sol=0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (A[i][j] && !vis[i][j]) {
                queue<pair<int,int>> q;
                q.push({i,j});
                while (true) {
                    
                }
            }
        }
    }

    return 0;
}