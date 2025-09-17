#include "bits/stdc++.h"
    using namespace std;
    #define ll long long

    // Conditional compilation
    #ifdef DEBUG
    #include "debug.h"
    #else
    #define debug(...) do { } while(0)
    #endif

    int query(int start, vector<int> S) {
        cout<<"? "<<start<<" "<<S.size()<<" ";
        for (auto s: S) {
            cout<<s<<" ";
        }
        cout<<"\n"<<flush;
        int ans;
        if(cin>>ans) {
            if (ans == -1) exit(0); 
            return ans;
        } else {
            exit(0);
        }
    }

    void solve() {
        int n;cin>>n;
        vector<int> locs(n);
        iota(locs.begin(),locs.end(),1);
        vector<int> dp(n+1);
        for (int i=1;i<n+1;i++) {
            dp[i]=query(i, locs);
        }
        int start = 1;
        for (int i = 2; i <= n; ++i) {
            if (dp[i] > dp[start]) start = i;
        }
        int L = dp[start];

        vector<int> path;
        path.push_back(start);

        // try to reconstruct order now
        vector<vector<int>> groups(n+2);
        for (int i=1;i<n+1;i++) {
            groups[dp[i]].push_back(i);
        }

        int current = start;
        for (int i=dp[start];i>=2  && path.size()<L;i--) {
            for (auto neighbour : groups[i-1]) {
                if (neighbour != current) {
                    if (query(current, vector<int>{current, neighbour}) == 2) {
                        path.push_back(neighbour);
                        current=neighbour;
                        break;
                    }
                }
            }
        }

        cout << "! " << path.size() << " ";
        for (auto p: path) {
            cout<<p<<" ";
        }
        cout<<"\n"<<flush;
    }   

    int main() {
        ios::sync_with_stdio(false); 
    #ifndef DEBUG
        cin.tie(nullptr);
    #endif

        int tests;
        cin >> tests;

        while (tests-- > 0) solve();

        return 0;
    }
