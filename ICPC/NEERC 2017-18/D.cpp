// NEERC 2017-18: Problem D

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

array<int, 3> add(array<int, 3> &x, array<int, 3> &y) {
    array<int, 3> r = x;
    for (int i = 0; i < 3; i++) r[i] += y[i];
    return r;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<pair<int, pair<array<int, 3>, array<int, 3>>>> rs = {
        {a, {{0, 0, 1}, {1, 1, 0}}},
        {b, {{0, 1, 0}, {1, 0, 1}}},
        {c, {{1, 0, 0}, {0, 1, 1}}},
    };
    sort(rs.rbegin(), rs.rend());
    vector<array<int, 3>> ans;

    if (rs[0].f == 2 && rs[1].f == 2 && rs[2].f == 2) {
        ans.push_back({0, 0, 0});
        ans.push_back({1, 1, 1});
        cout << ans.size() << '\n';
        for (auto x : ans) {
            for (auto y : x) cout << y << ' ';
            cout << '\n';
        }
        return;
    }
    if (rs[0].f == 3 && rs[1].f == 3 && rs[2].f == 2) {
        ans.push_back({0, 0, 0});
        ans.push_back({1, 1, 1});
        array<int, 3> p = {0, 0, 0};
        ans.push_back(add(p, rs[2].s.f));
        cout << ans.size() << '\n';
        for (auto x : ans) {
            for (auto y : x) cout << y << ' ';
            cout << '\n';
        }
        return;
    }

    if (rs[0].f > rs[1].f * rs[2].f) {
        cout << "-1\n";
        return;
    }

    if (rs[0].f >= rs[1].f + rs[2].f - 1) {
        // cout << "a,b,c: " << rs[0].f << ' ' << rs[1].f << ' ' << rs[2].f
        //      << '\n';
        ans.push_back({0, 0, 0});
        array<int, 3> c1 = {0, 0, 0}, c2 = {0, 0, 0};
        for (int i = 1; i < rs[2].f; i++) {
            c1 = add(c1, rs[1].s.f);
            ans.push_back(c1);
        }
        for (int i = 1; i < rs[1].f; i++) {
            c2 = add(c2, rs[2].s.f);
            ans.push_back(c2);
        }
        int cnt = rs[1].f + rs[2].f - 1;
        c1 = {0, 0, 0};
        while (cnt < rs[0].f) {
            c1 = add(c1, rs[1].s.f);
            c2 = {0, 0, 0};
            for (int y = 1; y < rs[1].f && cnt < rs[0].f; y++, cnt++) {
                c2 = add(c2, rs[2].s.f);
                ans.push_back(add(c1, c2));
            }
        }
    } else {
        ans.push_back({0, 0, 0});
        rs[0].f--, rs[1].f--, rs[2].f--;
        if ((rs[0].f + rs[1].f + rs[2].f) % 2) {
            ans.push_back(rs[0].s.s);
            rs[0].f--;
        }
        int sm = (rs[0].f + rs[1].f + rs[2].f) / 2;
        int x = sm - rs[0].f, y = sm - rs[1].f, z = sm - rs[2].f;
        array<int, 3> p = {0, 0, 0};
        for (int i = 0; i < x; i++) {
            p = add(p, rs[0].s.f);
            ans.push_back(p);
        }
        p = {0, 0, 0};
        for (int i = 0; i < y; i++) {
            p = add(p, rs[1].s.f);
            ans.push_back(p);
        }
        p = {0, 0, 0};
        for (int i = 0; i < z; i++) {
            p = add(p, rs[2].s.f);
            ans.push_back(p);
        }
    }

    cout << ans.size() << '\n';
    for (auto x : ans) {
        for (auto y : x) cout << y << ' ';
        cout << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}