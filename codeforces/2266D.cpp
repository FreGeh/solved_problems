/**
 *      author:  gemtec
 *      created: 21.09.2026 17:01:47
 *      link:
 *      idea:
 *      learning:
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

#ifdef DEBUG
#include "templates/debug.h"
#else
#define debug(...) do { } while(0)
#endif

//insights:
// wir können beliebig verschieben aber summe von allen bleibt gleich
// wenn wir immer nach vorne schieben, repeatet sich ein muster
// es gibt für jedes element einen minimalen wert den es annehmen kann, praktiisch potential
// potential muss man so anordnen dass aufsteigend

void solve() {
  int n;cin>>n;
  vector<int> heights(n);
  for (int i=0;i<n;i++) {
    cin>>heights[i];
    heights[i]-=i;
  }
  sort(heights.begin(), heights.end());

  int length=1, cur=1;
  for (int i=1;i<n;i++) {
    if (heights[i-1] + 1 == heights[i]) {
      cur++;
      length=max(length, cur);
    } else if (heights[i-1] == heights[i]) {
      continue;
    } else {
      cur=1;
    }
  }
  cout<<length<<endl;
}

int main() {
  ios::sync_with_stdio(false);
#ifndef DEBUG
  cin.tie(nullptr);
#endif

  int tests; cin >> tests;
  while (tests-- > 0) solve();
  return 0;
}