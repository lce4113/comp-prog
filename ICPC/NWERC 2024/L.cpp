// NWERC 2024: Problem L

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using iset = tree<int, null_type, less<int>, rb_tree_tag,
                  tree_order_statistics_node_update>;

int n, m, x, y;
vector<int> a, b;

bool check(int val) {
    // cout << "val: " << val << '\n';
    set<pair<pair<int, int>, int>> A;
    for (int i = 0; i < val; i++) A.insert({{a[i], y}, i});
    for (int i = val; i < n; i++) A.insert({{a[i], x}, i});
    for (auto v : b) {
        auto it = A.lower_bound({{v, 0}, 0});
        if (it == A.end()) return 0;
        auto p = *it;
        A.erase(it);
        if (--p.first.second) A.insert(p);
        // cout << v << '\n';
        // for (auto x : A) cout << x.first.first << ' ' << x.first.second <<
        // '\n'; cout << '\n';
    }
    return 1;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> x >> y;
    a.assign(n, 0), b.assign(m, 0);
    for (auto &z : a) cin >> z;
    for (auto &z : b) cin >> z;
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    int l = -1, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (l == -1) {
        cout << "impossible\n";
    } else {
        cout << l << '\n';
    }
}