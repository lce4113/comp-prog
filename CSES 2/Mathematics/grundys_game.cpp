// CSES Mathematics: Grundy's Game

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3;
vector<int> mex(MAXN + 1);
set<int> f;

void solve() {
    int n;
    cin >> n;
    cout << (f.count(n) ? "second\n" : "first\n");
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 3; i <= MAXN; i++) {
        set<int> prev;
        for (int x = 1, y = i - 1; x < y; x++, y--) {
            prev.insert(mex[x] ^ mex[y]);
        }
        auto it = prev.begin();
        while (it != prev.end() && *it == mex[i]) mex[i]++, it++;
    }

    for (int i = 0; i <= MAXN; i++)
        if (mex[i] == 0) f.insert(i);

    int t = 1;
    cin >> t;
    while (t--) solve();
}