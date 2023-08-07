// ––– USACO 2022 US Open Silver: Problem B –––

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
using vl = vector<ll>;
using pl = pair<ll, ll>;

int pos_rec(int num, vector<int> a, int l, int r) {
  if (r - l <= 1) return l;
  int mid = (l + r) / 2;
  if (num < a[mid]) return pos_rec(num, a, l, mid);
  return pos_rec(num, a, mid, r);
}

int pos(int num, vector<int> a) {
  int n = a.size();
  if (n == 0) return -2;
  if (num < a[0]) return -1;
  if (num > a[n - 1]) return n - 1;
  return pos_rec(num, a, 0, n);
}

void solve() {
  /* cout << pos(9, {1, 4, 6, 8}) << '\n'; */
  /* cout << (int)'a' - 'a' << '\n'; */

  string a, b;
  int q;
  /* int q = 1; */
  cin >> a >> b >> q;
  /* cin >> a >> b; */
  /* cout << a << ' ' << b << ' '; */

  vector<vector<int>> pos_a(18), pos_b(18);
  for (int i = 0; i < a.length(); i++) pos_a[a[i] - 'a'].push_back(i);
  for (int i = 0; i < b.length(); i++) pos_b[b[i] - 'a'].push_back(i);

  map<pair<char, char>, int> dp;
  for (int i = 0; i < q; i++) {
    string c;
    /* cin >> c; */
    c = "ab";

    for (int i = 0; i < c.length(); i++) {
      for (int k = i + 1; k < c.length(); k++) {
        if (dp.count({c[i], c[k]})) {
          if (dp[{c[i], c[k]}] == -1) goto a;
          continue;
        }
        /* int ais = (!pos_a.count(c[i]) ? 0 : pos_a[c[i]].size()); */
        /* int aks = (!pos_a.count(c[k]) ? 0 : pos_a[c[k]].size()); */
        /* int bis = (!pos_b.count(c[i]) ? 0 : pos_b[c[i]].size()); */
        /* int bks = (!pos_b.count(c[k]) ? 0 : pos_b[c[i]].size()); */
        if (pos_a[c[i] - 'a'].size() != pos_b[c[i] - 'a'].size()) goto a;
        if (pos_a[c[k] - 'a'].size() != pos_b[c[k] - 'a'].size()) goto a;
        /* cout << pos_a[c[i]][0] << ' ' << pos_b[c[i]][1] << ' '; */
        for (int l = 0; l < pos_a[c[i] - 'a'].size(); l++) {
          int x = pos(pos_a[c[i] - 'a'][l], pos_a[c[k] - 'a']);
          int y = pos(pos_b[c[i] - 'a'][l], pos_b[c[k] - 'a']);
          /* cout << x << ' ' << y << '\n'; */
          if (x != y) {
            dp[{c[i], c[k]}] = -1;
            goto a;
          }
        }
        dp[{c[i], c[k]}] = 1;
      }
    }

    cout << "Y";
    continue;
  a:
    /* continue; */
    cout << "N";
    continue;
  b:
    continue;
  }

  cout << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  /* int t; */
  /* cin >> t; */
  while (t--) solve();
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
