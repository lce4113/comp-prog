// CSES Range Queries: Salary Queries

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using iset =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    iset<pair<int, int>> st;
    for (int i = 0; i < n; i++) st.insert({a[i], i});

    while (q--) {
        char t;
        cin >> t;
        if (t == '!') {
            int k, x;
            cin >> k >> x;
            k--;
            st.erase({a[k], k});
            a[k] = x;
            st.insert({a[k], k});
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.order_of_key({r + 1, 0}) - st.order_of_key({l, 0})
                 << '\n';
        }
    }
}