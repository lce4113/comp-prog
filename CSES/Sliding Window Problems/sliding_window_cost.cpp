// CSES Sliding Window Problems: Sliding Window Cost

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using iset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
                  tree_order_statistics_node_update>;

#define int long long
#define f first
#define s second

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    iset c;
    int med = 0, ans = 0;
    for (int l = -k, r = 0; r < n; l++, r++) {
        if (l >= 0) {
            cout << ans << ' ';
            c.erase({a[l], l});
            if (c.size() % 2) med = c.find_by_order(c.size() / 2)->f;
            ans -= abs(med - a[l]);
        }
        c.insert({a[r], r});
        if (c.size() % 2) med = c.find_by_order(c.size() / 2)->f;
        ans += abs(med - a[r]);
    }
    cout << ans << '\n';
}