/**
 *    author:  gemtec
 *    created: 28.11.2025 15:06:32
 *    problem: https://codeforces.com/gym/102951/problem/D
**/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "compSetup/templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

const int max_val=100005;

vector<int> indices;
pair<int, int> queries[max_val];
pair<pair<int, int>, int> updates[max_val];

ll diff[max_val];
int widths[max_val];
ll prefix_interval[max_val];
ll prefix_sum[max_val];

int getIndex(int a) {
	return lower_bound(indices.begin(), indices.end(), a) - indices.begin();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n,q;cin>>n>>q;
    for (int i=0;i<n;i++) {
        int l,r,v;cin>>l>>r>>v;
        indices.push_back(l);
        indices.push_back(r);
        updates[i]={{l,r},v};
    }
    for (int i=0;i<q;i++) {
        int l,r;cin>>l>>r;
        indices.push_back(l);
        indices.push_back(r);
        queries[i]={l,r};
    }
    sort(indices.begin(), indices.end());
    indices.erase(unique(indices.begin(), indices.end()), indices.end());

    int m = (int)indices.size();

    for (int i = 0; i < n; i++) {
        auto [interval, v] = updates[i];
        int l = interval.first, r = interval.second;
        diff[getIndex(l) + 1] += v;
        diff[getIndex(r) + 1] -= v;
    }
    for (int i=0; i<m-1; i++) {
		widths[i+1] = indices[i+1] - indices[i];
	}
    for (int i=1; i<m; i++) {
		prefix_interval[i] = prefix_interval[i-1] + diff[i];
	}
    for (int i=1; i<m; i++) {
		prefix_sum[i] = prefix_sum[i-1] + prefix_interval[i] * widths[i];
	}

    for (int i = 0; i < q; i++) {
        auto [l, r] = queries[i];
        cout << prefix_sum[getIndex(r)] - prefix_sum[getIndex(l)] << endl;
    }

    return 0;
}