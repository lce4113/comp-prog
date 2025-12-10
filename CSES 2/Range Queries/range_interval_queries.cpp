// CSES Range Queries: Range Interval Queries

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

const int MAXN = 2e5;

struct Tree {
    int n;
    vector<int> a;
    int f(int x, int y) { return x + y; }
    Tree(int _n) : n(_n), a(2 * _n) {}
    void u(int pos) {
        for (a[pos += n] = 1; pos /= 2;) {
            a[pos] = f(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        int ans = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ans += a[l++];
            if (r % 2) ans += a[--r];
        }
        return ans;
    }
};

#define int long long

#define f first
#define s second

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> ps(n);
    for (int i = 0; i < n; i++) {
        cin >> ps[i].f;
        ps[i].s = i;
    }
    vector<pair<int, int>> qs;
    array<int, 4> Q[q];
    for (auto &[l, r, L, R] : Q) {
        cin >> l >> r >> L >> R;
        l--, r--;
        l--, L--;
        qs.emplace_back(R, r);
        qs.emplace_back(R, l);
        qs.emplace_back(L, r);
        qs.emplace_back(L, l);
    }

    sort(ps.begin(), ps.end());
    sort(qs.begin(), qs.end());

    Tree S(n);
    unordered_map<int, int> mp;
    int lp = n, lq = qs.size();
    int i = 0, j = 0;
    while (i < lp && j < lq) {
        if (ps[i] <= qs[j]) {
            S.u(ps[i].s);
            i++;
        } else {
            mp[qs[j].s + qs[j].f * MAXN] = S.q(0, qs[j].s + 1);
            j++;
        }
    }
    while (j < lq) {
        mp[qs[j].s + qs[j].f * MAXN] = S.q(0, qs[j].s + 1);
        j++;
    }

    for (auto [l, r, L, R] : Q) {
        int ans = mp[r + R * MAXN] - mp[l + R * MAXN] - mp[r + L * MAXN] +
                  mp[l + L * MAXN];
        cout << ans << '\n';
    }
}