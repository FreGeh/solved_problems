# Sorting & Searching

*`ll` equals `long long`*

## Distinct Numbers
- **Intuition**: 
```cpp
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin>>n;
    set<int> seen;
    for (int i=0;i<n;i++) {
        int x; cin>>x;
        seen.insert(x);
    }
    cout << seen.size();
    return 0;
}
```

## Apartments
- **Intuition**: 
```cpp
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n,m,k; cin>>n>>m>>k;
    vector<ll> applicants(n), apartments(m);
    for (ll i=0;i<n;i++) cin >> applicants[i];
    for (ll i=0;i<m;i++) cin >> apartments[i];

    sort(applicants.begin(), applicants.end()); sort(apartments.begin(), apartments.end());
    ll count = 0;
    for (ll i=0,j=0;i<n && j<m;) {
        if (abs(applicants[i]-apartments[j])<=k) j++; i++; count++;
        else if (applicants[i]>apartments[j]+k) j++;
        else i++;
    }
    cout << count;
    return 0;
}
```

## Ferris Wheel
- **Intuition**: 
```cpp

```

## Concert Tickets
- **Intuition**: 
```cpp

```

## Restaurant Customers
- **Intuition**: 
```cpp

```

## [Movie Festival](https://cses.fi/problemset/task/1629)
- **Intuition**: Sort all movies after their endtime
```cpp
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin>>n;
    vector<pair<int,int>> movies(n);
    for (int i=0; i<n; i++) {
        int a,b; cin>>a>>b;
        movies[i]={b,a};
    }
    sort(movies.begin(), movies.end());
    int cur=0;
    int sum=0;
    for (auto mov : movies) {
        if (mov.second >= cur) {
            cur=mov.first;
            sum++;
        }
    } 
    cout<<sum;
    return 0;
}
```

