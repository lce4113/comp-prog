// CSES Range Queries: Range Interval Queries

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using iset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
                  tree_order_statistics_node_update>;

#define f first
#define s second

const int MAXN = 2e5;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    pair<int, int> ps[n];
    for (int i = 0; i < n; i++) {
        cin >> ps[i].s;
        ps[i].f = i;
    }
    vector<pair<int, int>> qs;
    array<int, 4> Q[q];
    for (auto &[l, r, L, R] : Q) {
        cin >> l >> r >> L >> R;
        l--, r--;
        l--, L--;
        qs.emplace_back(r, R);
        qs.emplace_back(l, R);
        qs.emplace_back(r, L);
        qs.emplace_back(l, L);
    }

    sort(ps, ps + n);
    sort(qs.begin(), qs.end());

    iset S;
    unordered_map<int, int> mp;
    int lp = n, lq = qs.size();
    int i = 0, j = 0;
    while (i < lp && j < lq) {
        if (ps[i] <= qs[j]) {
            S.insert({ps[i].s, ps[i].f});
            i++;
        } else {
            mp[qs[j].f + qs[j].s * MAXN] = S.order_of_key({qs[j].s + 1, 0});
            j++;
        }
    }
    while (j < lq) {
        mp[qs[j].f + qs[j].s * MAXN] = S.order_of_key({qs[j].s + 1, 0});
        j++;
    }

    for (auto [l, r, L, R] : Q) {
        int ans = mp[r + R * MAXN] - mp[l + R * MAXN] - mp[r + L * MAXN] +
                  mp[l + L * MAXN];
        cout << ans << '\n';
    }
}