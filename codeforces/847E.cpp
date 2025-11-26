#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) do { } while(0)
#endif

void solve() {
    int n;cin>>n;
    vector<int> line(n,0);
    vector<int> packmen, stars;
    for (int i=0;i<n;i++) {
        char c; cin>>c;
        if (c=='P') {
            packmen.push_back(i);
        }
        else if (c=='*') {
            stars.push_back(i);
            //cout<<"pushed back star "<<i<<endl;
        }
    }
    int l=0, r=n, sol=0;
    while (l<=r) {
        int mid=l+(r-l)/2;
        //cout<<" mid is "<<mid<<endl;
        int reached=0;
        int sn=stars.size();
        //cout<<"sn is "<<sn<<endl;
        for (auto &p : packmen) {
            int rightmost=n-1;
            while (reached < sn && stars[reached]<=rightmost) {
                if (abs(p-stars[reached])>mid) {
                    //cout<<"doesnt work bc p is "<<p<<" and s is "<<stars[reached]<<" and rightmost is "<<rightmost<<" and mid is "<<mid<<endl;
                    break;
                } else {
                    if (stars[reached]<p) {
                        rightmost=max(mid-p+2*stars[reached],(mid+p+stars[reached])/2);
                        //cout<<" since star is LEFT packmen "<<p<<" reached star "<<stars[reached]<<" with rightmost defined as "<<rightmost<<endl;
                    } else {
                        rightmost=(p+mid);
                        //cout<<" since star is RIGHT packmen "<<p<<" reached star "<<stars[reached]<<" with rightmost defined as "<<rightmost<<endl;
                    }
                    while (reached < sn && stars[reached]<=rightmost) {
                        reached++;
                        //cout<<" since star is RIGHT packmen "<<p<<" reached star "<<stars[reached]<<" so reached is "<<reached<<" with rightmost defined as "<<rightmost<<endl;
                    }
                }
            }
        }
        if (reached==sn) {
            sol=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    if (packmen.size()==1) {
        int p= packmen[0];
        int first= stars[0];
        int last= stars[(int)stars.size()-1];
        //cout<<p<<" wants to go to first "<<first<<" and lastly "<<last<<endl;
        if (first==last) {
            sol=abs(p-first);
        } 
        else if(first<p&&last<p) sol=abs(p-first);
        else if(first>p&&last>p) sol=abs(p-last);
        else {
            int distfirst=abs(p-first), distlast=abs(p-last);

            if (first<p) {
                sol=0;
                sol+=min(distfirst,distlast);
                sol+=min(distfirst,distlast)+max(distfirst,distlast);
            } else {
                sol=last-p;
            }
        }
    }
    cout<<sol<<endl;
}

int main() {
    ios::sync_with_stdio(false); 
#ifndef DEBUG
    cin.tie(nullptr);
#endif

    solve();
    return 0;
}
