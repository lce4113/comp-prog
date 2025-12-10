// Codeforces Round 1033: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n, k;
vector<int> a;

pair<int, int> find(int m) {
    int i = 1, c = 0;
    while (c <= m && i < n) {
        c += i * (a[i] - a[i - 1]);
        i++;
    }
    i--;
    c -= i * (a[i] - a[i - 1]);
    return {(m - c) / i + a[i - 1], (m - c) % i};
}

int ch(int m) {
    auto [lo, lo_rem] = find(m);
    reverse(a.begin(), a.end());
    for (auto &x : a) x = -x;
    auto [hi, hi_rem] = find(m);
    hi = -hi;
    for (auto &x : a) x = -x;
    reverse(a.begin(), a.end());

    // cout << m << ' ' << lo << ' ' << hi << '\n';

    if (hi - lo > k + 1) return -1;
    int tot = m * k;
    for (auto x : a) {
        int y = min(max(x, lo), hi);
        tot += y * (y + 1) / 2;
    }
    tot -= hi * hi_rem, tot += (lo + 1) * lo_rem;
    return tot;
}

void solve() {
    cin >> n >> k;
    a.assign(n, 0);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    if (n == 1) {
        cout << a[0] * (a[0] + 1) / 2 << '\n';
        return;
    }
    // for (auto x : a) cout << x << ' ';
    // cout << '\n';
    // for (int i = 0; i < 10; i++) cout << i << ' ' << find(i) << '\n';
    int l = -1, r = reduce(a.begin(), a.end()) - a[0] * n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (ch(m) == -1) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << ch(r) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}