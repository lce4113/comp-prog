// USACO 2021 January Silver: Problem B

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define pb push_back
#define f first
#define s second

struct Seg {
  int n;
  vi seg;

  void init(vi a) {
    n = pow(2, ceil(log2(a.size())));
    seg.assign(n, 0);
    for (auto x : a) seg.pb(x);
    for (int i = 0; i < n - a.size(); i++) seg.pb(0);
    for (int i = n - 1; i >= 0; i--) {
      seg[i] = min(seg[2 * i], seg[2 * i + 1]);
    }
  }

  int query(int L, int R) { return query(L, R, 0, n, 1); }
  int query(int L, int R, int l, int r, int i) {
    if (l >= R || r <= L) return INT_MAX;
    if (l >= L && r <= R) return seg[i];
    int ans = INT_MAX;
    ans = min(ans, query(L, R, l, (l + r) / 2, 2 * i));
    ans = min(ans, query(L, R, (l + r) / 2, r, 2 * i + 1));
    return ans;
  }
};

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  vector<int> fence;
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    fence.pb(x - 'A');
  }
  Seg segtree;
  segtree.init(fence);

  map<int, vi> colors;
  for (int i = 0; i < n; i++) colors[fence[i]].pb(i);
  map<int, set<pair<int, int>>> colors_pfs;
  for (auto c : colors) {
    colors_pfs[c.f].insert({-1, 0});
    colors_pfs[c.f].insert({c.s[0], 1});
    int tot = 1;
    for (int i = 0; i < c.s.size() - 1; i++) {
      int mn = segtree.query(c.s[i] + 1, c.s[i + 1]);
      if (mn < c.f) tot++;
      /* cout << c.s[i] + 1 << ' ' << c.s[i + 1] << ' ' << mn << '\n'; */
      colors_pfs[c.f].insert({c.s[i + 1], tot});
    }
  }

  /* for (auto x : colors_pfs) { */
  /*   cout << x.f << " : "; */
  /*   for (auto y : x.s) { */
  /*     cout << y.f << ' ' << y.s << ", "; */
  /*   } */
  /*   cout << '\n'; */
  /* } */

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int ans = 0;
    for (auto c : colors_pfs) {
      ans += (--c.s.lower_bound({l, -1}))->s;
      if (c.s.upper_bound({r, INT_MAX}) != c.s.end()) {
        ans += c.s.rbegin()->s - c.s.upper_bound({r, INT_MAX})->s + 1;
      }
    }
    cout << ans << '\n';
  }
}
