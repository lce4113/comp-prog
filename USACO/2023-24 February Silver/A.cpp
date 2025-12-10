// USACO 2023-24 February Silver
// Problem 1: Target Practice II

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

bool chp(int m, vector<pair<int, int>> ps, vector<int> s) {
    int n = ps.size();
    vector<long double> ms;
    for (auto x : ps) {
        ms.push_back(((long double)x.s - m) / x.f);
    }
    sort(ms.begin(), ms.end());
    for (int i = 0; i < n; i++) {
        if (ms[i] < s[i]) return false;
    }
    return true;
}

bool chn(int m, vector<pair<int, int>> ps, vector<int> s) {
    int n = ps.size();
    vector<long double> ms;
    for (auto x : ps) {
        ms.push_back(((long double)x.s - m) / x.f);
    }
    sort(ms.begin(), ms.end());
    for (int i = 0; i < n; i++) {
        if (ms[i] > s[i]) return false;
    }
    return true;
}

void solve() {
    int n, x1;
    cin >> n >> x1;
    vector<pair<int, int>> TR, BR, L;
    for (int i = 0; i < n; i++) {
        int y1, y2, x2;
        cin >> y1 >> y2 >> x2;
        L.push_back({x1, y1});
        L.push_back({x1, y2});
        TR.push_back({x2, y2});
        BR.push_back({x2, y1});
    }
    vector<int> a(4 * n);
    for (auto &x : a) cin >> x;

    vector<int> pos, neg;
    for (auto x : a) {
        if (x > 0) pos.push_back(x);
        if (x < 0) neg.push_back(x);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    if ((int)pos.size() < n || (int)neg.size() < n) {
        cout << "-1\n";
        return;
    }

    sort(L.begin(), L.end());
    int i = 0;
    for (; i < (int)neg.size() - n; i++) {
        TR.push_back(L[i]);
    }
    for (; i < 2 * n; i++) {
        BR.push_back(L[i]);
    }

    // for (auto x : TR) cout << x.f << ' ' << x.s << ", ";
    // cout << '\n';
    // for (auto x : BR) cout << x.f << ' ' << x.s << ", ";
    // cout << '\n';
    // cout << '\n';
    // for (auto x : pos) cout << x << ' ';
    // cout << '\n';
    // for (auto x : neg) cout << x << ' ';
    // cout << '\n';
    // cout << '\n';

    int l = -1e18, r = 1e18 + 1, m = (l + r) / 2;
    for (; r - l > 1; m = (l + r) / 2) {
        if (chp(m, BR, pos)) {
            l = m;
        } else {
            r = m;
        }
    }
    int ans = l;

    l = -1e18 - 1, r = 1e18, m = (l + r) / 2;
    for (; r - l > 1; m = (l + r) / 2) {
        if (chn(m, TR, neg)) {
            r = m;
        } else {
            l = m;
        }
    }
    ans = r - ans;
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}