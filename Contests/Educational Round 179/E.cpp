// Educational Codeforces Round 179: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> bc, ca, cb, ba;
    while (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if (x == 'a' && y == 'b' || x == 'a' && y == 'c') continue;
        if (x == 'b' && y == 'c') {
            bc.push_back(i);
            continue;
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}