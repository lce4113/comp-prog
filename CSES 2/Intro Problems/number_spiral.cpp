// CSES Introductory Problems: Number Spiral

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int x, y;
    cin >> x >> y;
    int sq = max(x, y);
    int pos = sq - y + x - 1;
    cout << (sq % 2 ? sq * sq - pos : (sq - 1) * (sq - 1) + 1 + pos) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}