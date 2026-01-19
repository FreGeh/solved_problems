/**
 *      author:  gemtec
 *      created: 19.01.2026 13:10:44
 *      link: https://domjudge.iti.kit.edu/main/team/problems/77/statement
 *      idea: aho-carosick
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

struct AhoCorasick {
    static const int A = 26; // alphabet size
    static const int OFF = 'a';

    struct Vert {
        array<int, A> next = {}; // Transitions
        int count = 0; // marked
    };

    vector<Vert> trie;

    AhoCorasick() { trie.emplace_back(); } // init

    void add_string(const string& s) {
        int v = 0;
        for(char c : s) {
            int i = c - OFF;
            if(!trie[v].next[i]) {
                trie[v].next[i] = trie.size();
                trie.emplace_back();
            }
            v = trie[v].next[i];
        }
        trie[v].count++; // mark end of word
    }

    void finalize() {
        queue<array<int,4>> q; // {current_node, parent, parent_link, char_from_parent}
        q.push({0, 0, 0, 0});

        while(!q.empty()) {
            auto [v, p, plink, pch] = q.front(); q.pop();

            int link = (p == 0) ? 0 : trie[plink].next[pch]; // suffix link

            if (v != 0) trie[v].count += trie[link].count; // propagate counts

            for(int c = 0; c < A; ++c) {
                if(trie[v].next[c]) { // child exists
                    q.push({trie[v].next[c], v, link, c});
                } else { // no child
                    trie[v].next[c] = trie[link].next[c];
                }
            }
        }
    }

    ll query(const string& s) {
        ll res = 0;
        int v = 0;
        for(char c : s) {
            v = trie[v].next[c - OFF];
            res += trie[v].count;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, k; cin>>n>>k;

    AhoCorasick ac;
    for (int i=0; i<k; i++) {
        string s; cin >> s;
        ac.add_string(s);
    }
    ac.finalize();

    vector<string> grid(n);
    for (int i=0; i<n; i++) { 
        cin >> grid[i]; 
    }

    ll ans = 0;

    for (const string& row : grid) { // horizontal
        ans += ac.query(row); 
    }

    for (int j=0; j<n; j++) { // vertical
        string col; col.reserve(n);
        for(int i=0; i<n; i++) { 
            col += grid[i][j]; 
        }
        ans += ac.query(col);
    }

    cout<<ans<<"\n";

    return 0;
}