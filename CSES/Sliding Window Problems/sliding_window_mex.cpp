// CSES Sliding Window Problems: Sliding Window Mex

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag,
                         tree_order_statistics_node_update>;

int mex(indexed_set &c) {
    // for (auto x : c) cout << x << ' ';
    // cout << '\n';
    int l = -1, r = c.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (*c.find_by_order(m) == m) {
            l = m;
        } else {
            r = m;
        }
    }
    return l + 1;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    indexed_set c;
    map<int, int> store;
    for (int i = 0; i < k; i++) store[a[i]]++, c.insert(a[i]);
    // cout << *c.find_by_order(1) << '\n';
    cout << mex(c) << ' ';
    for (int l = 0, r = k; r < n; l++, r++) {
        store[a[l]]--;
        store[a[r]]++;
        c.insert(a[r]);
        if (store[a[l]] == 0) c.erase(a[l]);
        cout << mex(c) << ' ';
    }
    cout << '\n';
}