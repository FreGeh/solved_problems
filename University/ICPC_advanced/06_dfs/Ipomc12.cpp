/**
 *      author:  gemtec
 *      created: 13.02.2026 13:16:01
 *      link:
 *      idea:
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }

    vector<int> tin(n+1,-1),low(n+1),par(n+1),pe(n+1,-1),it(n+1);
    vector<char> br(m);
    int timer=0;

    for(int r=1;r<=n;r++){
        if(tin[r]!=-1) continue;
        vector<int> st;st.push_back(r);
        par[r]=0;pe[r]=-1;

        while(!st.empty()){
            int v=st.back();
            if(tin[v]==-1) tin[v]=low[v]=timer++;

            if(it[v]==(int)adj[v].size()){
                st.pop_back();
                int p=par[v],eid=pe[v];
                if(p){
                    low[p]=min(low[p],low[v]);
                    if(low[v]>tin[p]) br[eid]=1;
                }
                continue;
            }

            auto [to,id]=adj[v][it[v]++];
            if(id==pe[v]) continue;

            if(tin[to]==-1){
                par[to]=v;pe[to]=id;
                st.push_back(to);
            }
            else low[v]=min(low[v],tin[to]);
        }
    }

    vector<int> cc(n+1,-1);
    int cc_num=0;
    for(int i=1;i<=n;i++){
        if(cc[i]!=-1) continue;
        queue<int> q;q.push(i);cc[i]=cc_num;
        while(!q.empty()){
            int v=q.front();q.pop();
            for(auto [to,id]:adj[v]) if(cc[to]==-1){
                cc[to]=cc_num;q.push(to);
            }
        }
        cc_num++;
    }

    vector<int> mx(cc_num);
    vector<char> seen(n+1);
    for(int i=1;i<=n;i++){
        if(seen[i]) continue;
        int sz=0;
        queue<int> q;q.push(i);seen[i]=1;
        while(!q.empty()){
            int v=q.front();q.pop();sz++;
            for(auto [to,id]:adj[v]){
                if(br[id]) continue;
                if(!seen[to]) seen[to]=1,q.push(to);
            }
        }
        mx[cc[i]]=max(mx[cc[i]],sz);
    }

    int ans=INT_MAX;
    for(int c=0;c<cc_num;c++) ans=min(ans,mx[c]-1);
    cout<<ans<<"\n";
    return 0;
}