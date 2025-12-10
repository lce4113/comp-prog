// CSES Sliding Window Problems: Sliding Window Median

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using indexed_set = tree<pair<int, int>, null_type, less<pair<int, int>>,
                         rb_tree_tag, tree_order_statistics_node_update>;

#define f first
#define s second

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    indexed_set c;
    for (int i = 0; i < k; i++) c.insert({a[i], i});
    cout << c.find_by_order((c.size() - 1) / 2)->f << ' ';
    for (int l = 0, r = k; r < n; l++, r++) {
        c.insert({a[r], r});
        c.erase({a[l], l});
        cout << c.find_by_order((c.size() - 1) / 2)->f << ' ';
    }
    cout << '\n';
}