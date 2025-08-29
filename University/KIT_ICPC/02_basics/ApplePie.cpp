#include "bits/stdc++.h"
using namespace std;

struct household {
    int cakes;
    int horses;
    bool operator<(const household &h) const {
        return horses * h.cakes < h.horses * cakes;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, P;
    cin >> H >> P;

    P = P - H;
    priority_queue <household> pq;
    int h;
    for (int i=0; i < H; i++) {
        cin >> h;
        pq.push({1, h});
    }

    while (P > 0) {
        auto top = pq.top();
        pq.pop();

        pq.push({top.cakes + 1, top.horses});
        P--;
    }
    
    auto top = pq.top();
    int maxSlices = (top.horses + top.cakes - 1) / top.cakes;

    cout << maxSlices << "\n";

    return 0;
}