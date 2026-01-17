#include "bits/stdc++.h"
using namespace std;
#define ll long long

bool passable(char ch, int parity) {
    if (ch == '#') {
        return false;
    } 
    if (ch == 'o') {
        if (parity%2==0) {
            return true;
        } else {
            return false;
        }
    }
    if (ch == 'x') {
        if (parity%2==1) {
            return true;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    const int INF = 1e9;
    const int hchange[4]={0,0,1,-1};
    const int wchange[4]={-1,1,0,0};

    int h,w;cin>>h>>w;
    pair<int,int> start{0,0};
    pair<int,int> goal{0,0};
    vector<vector<char>> A(h, vector<char>(w));
    for (int i=0;i<h;i++) {
        for (int j=0;j<w;j++) {
            cin>>A[i][j];
            if (A[i][j] == 'S') {
                start={i,j};
            } else if (A[i][j] == 'G') {
                goal={i,j};
            }
        }
    }
    vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(2, INF)));
    queue<tuple<int,int,int>> q;
    dist[start.first][start.second][0] = 0;
    q.emplace(start.first, start.second, 0);
    while (!q.empty()) {
        auto [i,j,p] = q.front(); q.pop();
        int d = dist[i][j][p];
        if (i == goal.first && j == goal.second) {
            cout << d << '\n';
            return 0;
        }
        for (int k=0;k<4;k++) {
            int newh= i + hchange[k];
            int neww= j + wchange[k];
            if (newh>=0 && newh<h && neww >= 0 && neww < w) {
                char ch = A[newh][neww];
                if (passable(ch, p)) {
                    int newp = p;
                    if (ch == '?') newp = p ^ 1;
                    if (dist[newh][neww][newp] == INF) {
                        dist[newh][neww][newp] = d + 1;
                        q.emplace(newh, neww, newp);
                    }
                }
            }
        }
    }
    cout << "-1" << "\n";
    // bfs with walking over mod2=0 switch cells (closed=obstable, open=empty)
    // bfs with walking over mod2=1 switch cells (closed=empty, open=obstacle)

    return 0;
}
