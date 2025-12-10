// Codeforces Round 1000: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

vector<int> da, db;

pair<int, int> best(pair<int, int> mxp, pair<int, int> nxt, int n, int m) {
    if (nxt.f < 0 || nxt.s < 0) return mxp;
    if (nxt.f + 2 * nxt.s > m || nxt.s + 2 * nxt.f > n) return mxp;
    // cout << "nxt: " << nxt.f << ' ' << nxt.s << '\n';
    // cout << da[nxt.f] << ' ' << db[nxt.s] << '\n';
    if (mxp.f == -1) return nxt;
    if (da[nxt.f] + db[nxt.s] > da[mxp.f] + db[mxp.s]) return nxt;
    return mxp;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (n > m) swap(n, m), swap(a, b);

    if (n == 1 && m == 1) {
        cout << "0\n";
        return;
    }

    da.clear(), db.clear();
    da.push_back(0), db.push_back(0);
    for (int l = 0, r = n - 1; r > l; l++, r--) {
        da.push_back(da.back() + a[r] - a[l]);
    }
    for (int l = 0, r = m - 1; r > l; l++, r--) {
        db.push_back(db.back() + b[r] - b[l]);
    }

    // for (auto x : da) cout << x << ' ';
    // cout << '\n';
    // for (auto x : db) cout << x << ' ';
    // cout << '\n';
    // cout << '\n';

    int N = m > 2 * n ? n : (n + m) / 3;
    vector<int> ans(N);
    pair<int, int> l = {N, 0}, r = {0, N}, mxp;
    int mx = -1;
    for (int ca = 0, cb = N; cb >= 0; ca++, cb--) {
        if (ca < 0 || cb < 0) continue;
        if (ca + 2 * cb > m || cb + 2 * ca > n) continue;
        if (ca < l.f) l = {ca, cb};
        if (ca > r.f) r = {ca, cb};
        if (da[ca] + db[cb] > mx) {
            mx = da[ca] + db[cb];
            mxp = {ca, cb};
        }
    }
    ans[N - 1] = da[mxp.f] + db[mxp.s];

    // cout << l.f << ' ' << l.s << '\n';
    // cout << r.f << ' ' << r.s << '\n';

    for (int tot = N - 1; tot > 0; tot--) {
        l.f -= 2, l.s++, r.f++, r.s -= 2;
        pair<int, int> nmxp = {-1, -1};
        nmxp = best(nmxp, l, n, m);
        nmxp = best(nmxp, r, n, m);
        nmxp = best(nmxp, {mxp.f - 1, mxp.s}, n, m);
        nmxp = best(nmxp, {mxp.f, mxp.s - 1}, n, m);
        mxp = nmxp;
        ans[tot - 1] = da[mxp.f] + db[mxp.s];
    }

    cout << N << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
    // cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}