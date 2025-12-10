// Codeforces Round 951: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, d;
    cin >> n >> d;
    map<int, set<pair<int, int>>> pos, neg;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pos[y - x].insert({x, i + 1});
        neg[y + x].insert({x, i + 1});
    }

    // for (auto [yx, xs] : pos) {
    //     cout << yx << ": ";
    //     for (auto [x, i] : xs) cout << x << ' ';
    //     cout << '\n';
    // }

    for (auto [yx, xs] : pos) {
        for (auto [x1, i1] : xs) {
            auto it = xs.lower_bound({x1 + d / 2, -1});
            if (it == xs.end()) continue;
            auto [x2, i2] = *it;
            if (x2 != x1 + d / 2) continue;

            // cout << x1 << ' ' << x2 << '\n';
            // cout << yx + d << ' ' << x1 - d / 2 << '\n';

            it = pos[yx - d].lower_bound({x2, -1});
            if (it != pos[yx - d].end()) {
                auto [x3, i3] = *it;
                if (x3 <= x2 + d / 2) {
                    cout << i1 << ' ' << i2 << ' ' << i3 << '\n';
                    return;
                }
            }

            it = pos[yx + d].lower_bound({x1 - d / 2, -1});
            if (it == pos[yx + d].end()) continue;
            auto [x3n, i3n] = *it;
            if (x3n <= x1) {
                cout << i1 << ' ' << i2 << ' ' << i3n << '\n';
                return;
            }
        }
    }

    for (auto [yx, xs] : neg) {
        for (auto [x1, i1] : xs) {
            auto it = xs.lower_bound({x1 + d / 2, -1});
            if (it == xs.end()) continue;
            auto [x2, i2] = *it;
            if (x2 != x1 + d / 2) continue;

            // cout << x1 << ' ' << x2 << '\n';
            // cout << yx + d << ' ' << x1 - d / 2 << '\n';

            it = neg[yx - d].lower_bound({x1 - d / 2, -1});
            if (it != neg[yx - d].end()) {
                auto [x3, i3] = *it;
                if (x3 <= x1) {
                    cout << i1 << ' ' << i2 << ' ' << i3 << '\n';
                    return;
                }
            }

            it = neg[yx + d].lower_bound({x2, -1});
            if (it == neg[yx + d].end()) continue;
            auto [x3n, i3n] = *it;
            if (x3n <= x2 + d / 2) {
                cout << i1 << ' ' << i2 << ' ' << i3n << '\n';
                return;
            }
        }
    }

    cout << "0 0 0\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}