// Codeforces Round 1061: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int INF = 1e18;

int n;
vector<int> a;

pair<int, int> best(set<int> rem) {
    pair<int, int> res = {-1, -1};
    int mi = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (rem.count(i)) continue;
        if (mi != -1 && (res.f == -1 || a[mi] - a[i] > a[res.f] - a[res.s]))
            res = {mi, i};
        if (mi == -1 || a[i] > a[mi]) mi = i;
    }
    return res;
}

void solve() {
    cin >> n;
    a.assign(n, 0);
    for (auto &x : a) cin >> x;
    auto b1 = best({});
    auto b2 = best({b1.f});
    auto b3 = best({b1.s});
    auto b4 = best({b1.f, b2.f});
    auto b5 = best({b1.f, b2.s});
    auto b6 = best({b1.s, b3.f});
    auto b7 = best({b1.s, b3.s});
    int ans = INF;
    ans = min(ans, max(a[b4.f] - a[b4.s], a[b5.f] - a[b5.s]));
    ans = min(ans, max(a[b6.f] - a[b6.s], a[b7.f] - a[b7.s]));
    for (int i = 0; i < n; i++) {
        int mx = -INF;
        if (b2.f != i && b2.s != i) mx = max(mx, a[b2.f] - a[b2.s]);
        if (b3.f != i && b3.s != i) mx = max(mx, a[b3.f] - a[b3.s]);
        if (b4.f != i && b4.s != i) mx = max(mx, a[b4.f] - a[b4.s]);
        if (b5.f != i && b5.s != i) mx = max(mx, a[b5.f] - a[b5.s]);
        if (b6.f != i && b6.s != i) mx = max(mx, a[b6.f] - a[b6.s]);
        if (b7.f != i && b7.s != i) mx = max(mx, a[b7.f] - a[b7.s]);
        ans = min(ans, mx);
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}