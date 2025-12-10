// Codeforces Round 1065: Problem G

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int M = 1e6 + 3;
vector<int> f(M + 1, 1);

int binexp(int a, int b = M - 2) {
    int res = 1;
    for (; b; a *= a, a %= M, b /= 2) {
        if (b & 1) res *= a, res %= M;
    }
    return res;
}

int fact(int v) {
    int res = binexp(f[M], v / M);
    res *= f[v % M], res %= M;
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    int ds = 1e9;
    for (int i = 0; i < n; i++) {
        int c = a[i], cnt = 0;
        while (c <= b[i]) c *= 2, cnt++;
        ds = min(ds, cnt - 1);
    }
    // cout << ds << '\n';
    int res = ds;
    vector<vector<int>> cs(ds + 1);
    for (int i = 0; i < n; i++) {
        int c = b[i];
        for (int j = 0; j < ds; j++) {
            if (c & 1) cs[ds - j].push_back(1), res++;
            c >>= 1;
        }
        cs[0].push_back(c - a[i]), res += c - a[i];
    }
    int ans = 1;
    for (auto c : cs) {
        if (c.size() == 0) continue;
        ans *= fact(reduce(c.begin(), c.end())), ans %= M;
        for (auto v : c) {
            ans *= binexp(f[v]), ans %= M;
        }
    }
    cout << res << ' ' << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= M; i++) {
        f[i] = f[i - 1] * i % M;
    }

    int t = 1;
    cin >> t;
    while (t--) solve();
}