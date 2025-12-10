// CSES Additional Problems I: Pyramid Array

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define int long long

using iset = tree<int, null_type, less<int>, rb_tree_tag,
                  tree_order_statistics_node_update>;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    iset L, R;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = L.size() - L.order_of_key(a[i]);
        L.insert(a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        int c = R.size() - R.order_of_key(a[i]);
        ans[i] = min(ans[i], c);
        R.insert(a[i]);
    }
    cout << reduce(ans.begin(), ans.end()) << '\n';
}