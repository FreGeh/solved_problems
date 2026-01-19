/**
 *      author:  gemtec
 *      created: 19.01.2026 11:18:12
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

vector<int> get_z(const string& s) {
    int n=s.size();
    vector<int> z(n);
    for(int i=1, l=0, r=0; i<n; i++) {
        if(i<=r) { 
            z[i]=min(r-i+1, z[i-l]); 
        }
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]) { 
            z[i]++; 
        }
        if(i+z[i]-1>r) { 
            l=i;
            r=i+z[i]-1; 
        }
    }
    return z;
}

vector<int> get_p(const string& s) {
    int n=s.size();
    vector<int> p(n);
    for(int i=1; i<n; i++) {
        int j=p[i-1];
        while(j>0 && s[i]!=s[j]) { 
            j=p[j-1]; 
        }
        if(s[i]==s[j]) { 
            j++; 
        }
        p[i]=j;
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string type; int n;
    cin>>type>>n;
    
    vector<int> a(n);
    for(int& x : a) cin>>x;

    string s(n, 0); 
    s[0]='a';

    if(type == "p2z") {
        for(int i=1; i<n; i++) {
            if(a[i]) s[i]=s[a[i]-1];
            else {
                for(char c='a'; c<='z'; c++) {
                    int j=a[i-1];
                    while(j>0 && c!=s[j]) { 
                        j=a[j-1]; 
                    }
                    if(c==s[j]) j++;
                    if(j==0) { 
                        s[i]=c; 
                        break; 
                    }
                }
            }
        }
        vector<int> z = get_z(s);
        for(int i=0; i<n; i++) cout<<z[i]<<" ";
    } else {
        vector<int> mask(n);
        int l=0, r=0;
        for(int i=1; i<n; i++) {
            if(i<=r) { 
                s[i]=s[i-l]; 
            }
            
            if(i+a[i]-1 > r) {
                for(int k=max(r+1, i); k<i+a[i]; k++) s[k]=s[k-i];
                l=i;
                r=i+a[i]-1;
            }
            
            if(i+a[i] < n) { 
                mask[i+a[i]] |= (1<<(s[a[i]]-'a')); 
            }

            if(!s[i]) {
                int bad=mask[i];
                if(a[i]==0) bad |= (1<<(s[0]-'a'));
                for(int c=0; c<26; c++) {
                    if(!((bad>>c)&1)) { 
                        s[i]=c+'a'; 
                        break; 
                    }
                }
            }
        }
        vector<int> p = get_p(s);
        for(int i=0; i<n; i++) cout<<p[i]<<" ";
    }
    
    return 0;
}