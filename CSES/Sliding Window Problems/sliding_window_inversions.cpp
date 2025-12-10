// CSES Sliding Window Problems: Sliding Window Inversions

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define int long long
using iset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
                  tree_order_statistics_node_update>;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    iset c;
    int ans = 0;
    for (int l = -k, r = 0; r < n; l++, r++) {
        if (l >= 0) {
            cout << ans << ' ';
            ans -= c.order_of_key({a[l], -1});
            c.erase({a[l], l});
        }
        ans += c.size() - c.order_of_key({a[r], 1e9});
        c.insert({a[r], r});
    }
    cout << ans << '\n';
}
