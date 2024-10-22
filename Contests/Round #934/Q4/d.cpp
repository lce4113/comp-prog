// CodeForces Round #934: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  string s;
  int n, q;
  cin >> n >> q >> s;
  set<int> diff, diff2;
  diff.insert(n - 1), diff2.insert(n - 1);
  for (int i = 0; i < n - 1; i++) {
    if (s[i] != s[i + 1]) diff.insert(i);
    if (i != n - 2 && s[i] != s[i + 2]) diff2.insert(i);
  }
  string ps = "$";
  for (auto x : s) ps += x, ps += '$';
  int pn = ps.size(), l = 0, r = 0;
  vector<int> p(pn);
  for (int i = 0; i < pn; i++) {
    p[i] = max(0ll,min(r - i, p[l + (r - i)]));
    while (i - p[i] >= 0 && i + p[i] < pn && ps[i - p[i]] == ps[i + p[i]]) {
      p[i]++;
    }
    if (i + p[i] > r) l = i - p[i], r = i + p[i];
  }
  /* for (auto x : diff) cout << x << ' '; */
  /* cout << '\n'; */
  /* for (auto x : diff2) cout << x << ' '; */
  /* cout << '\n'; */
  /* for (auto x : p) cout << x << ' '; */
  /* cout << '\n'; */
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int ans;
    if (*diff.lower_bound(l) >= r) {
      ans = 0;
    } else if (*diff2.lower_bound(l) >= r - 1) {
      int len = (r - l + 1) / 2;
      ans = len * (len + 1);
    } else if (p[l + r + 1] - 1 >= r - l + 1) {
      int len = r - l;
      ans = len * (len + 1) / 2 - 1;
    } else {
      int len = r - l + 1;
      ans = len * (len + 1) / 2 - 1;
    }
    cout << ans << '\n';
  }
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
