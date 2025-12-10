// Codeforces Round 1056: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> ys;
    int my = -1;
    while (k--) {
        int x, y;
        cin >> x >> y;
        my = max(my, y);
        ys[y]++;
    }
    if (n == 1) {
        cout << (ys[2] % 2 ? "Mimo\n" : "Yuyu\n");
        return;
    }
    for (auto x : ys) {
        if (x.f == 1) continue;
        if (x.s % 2) {
            cout << "Mimo\n";
            return;
        }
    }
    cout << "Yuyu\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}