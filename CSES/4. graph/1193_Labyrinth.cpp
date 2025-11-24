#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) do { } while(0)
#endif

int solve() {
    int n,m;cin>>n>>m;
    n+=2;m+=2;
    pair<int,int> s, e;
    vector<vector<int>> L(n, vector<int>(m, -1));
    for (int i=1;i<n-1;i++) {
        for (int j=1;j<m-1;j++) {
            char c; cin>>c;
            //cout<<c;
            if (c=='A') {
                s={i,j};
                L[i][j]=0;
            }
            else if (c=='B') {
                e={i,j};
                L[i][j]=0;
            }
            else if (c=='.') L[i][j]=0;
        }
        //cout<<endl;
    }
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<char>> parent(n, vector<char>(m, ' '));
    queue<pair<int, int>> q;
    q.push(s);
    dist[s.first][s.second] = 0; 

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    char dir[] = {'R','L','D','U'};

    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        //cout<<"currently in queue: "<<v.first<<" "<<v.second<<endl;
        if (v == e) {
            cout<<"YES"<<endl;
            cout<<dist[v.first][v.second]<<endl;
            int y=v.first,x=v.second;
            string output;
            for (int i=0;i<dist[v.first][v.second];i++) {
                char direction=parent[y][x];
                //cout<<"found direction at "<<y<<" "<<x<<endl;
                if (direction=='R') x+=dx[1], y+=dy[1];
                else if (direction=='L') x+=dx[0], y+=dy[0];
                else if (direction=='D') x+=dx[3], y+=dy[3];
                else if (direction=='U') x+=dx[2], y+=dy[2];
                output+=direction;
            }
            reverse(output.begin(), output.end());
            cout<<output<<endl;
            return 0;
        }
        for (int i=0;i<4;i++) {
            int x=dx[i];
            int y=dy[i];
            char di=dir[i];
            //cout<<"checking neighbour: "<<v.first+y<<" "<<v.second+x<<" with value "<<L[v.first+y][v.second+x]<<" and direction: "<<di<<endl;
            if (dist[v.first+y][v.second+x]==-1 && L[v.first+y][v.second+x]==0) {
                dist[v.first+y][v.second+x]=dist[v.first][v.second]+1;
                parent[v.first+y][v.second+x]=di;
                q.push({v.first+y,v.second+x});
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    solve();
    return 0;
}
