// Codeforces Round 1040: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int c0 = 0, c1 = 0, c2 = 0;
    for (auto &x : a) {
        c0 += x == 0;
        c1 += x == 1;
        c2 += x == 2;
    }
    int tot = reduce(a.begin(), a.end());
    if (k < tot) {
        for (auto x : a) cout << x << ' ';
        cout << '\n';
        return;
    }
    if (k > tot + 1 || k == tot) {
        cout << "-1\n";
        return;
    }
    while (c0--) cout << "0 ";
    while (c2--) cout << "2 ";
    while (c1--) cout << "1 ";
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}