// USACO 2023 US Open Silver: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
using vi = vector<int>;
#define pb push_back
using pi = pair<int, int>;
#define f first
#define s second

int32_t main() {
  int n;
  cin >> n;
  vi a(n);
  for (auto &x : a) cin >> x;
  vi vals = a;
  sort(a.begin(), a.end());
  vi pfs(n + 1, 0);
  for (int i = 0; i < n; i++) pfs[i + 1] = pfs[i] + a[i];
  /* for (auto x : sa) cout << x.f << ' ' << x.s << ','; */
  /* cout << '\n'; */

  int ans1 = 0;
  for (int i = 0; i < n; i++) ans1 += (i + 1) * a[i];
  int q;
  cin >> q;
  while (q--) {
    int ans = ans1;
    int pos, nval;
    cin >> pos >> nval;
    pos--;
    int currval = vals[pos];
    int pos1 = lower_bound(a.begin(), a.end(), currval) - a.begin();
    int pos2 = lower_bound(a.begin(), a.end(), nval) - a.begin();
    /* cout << ans << '\n'; */
    if (pos2 > pos1) {
      ans -= (pos1 + 1) * currval, ans += pos2 * nval;
      /* cout << (pos1 + 1) * currval << ' ' << pos2 * nval << '\n'; */
      ans -= pfs[pos2] - pfs[pos1 + 1];
      /* cout << pfs[pos2] - pfs[pos1 + 1] << '\n'; */
    } else {
      ans -= (pos1 + 1) * currval, ans += (pos2 + 1) * nval;
      /* cout << (pos1 + 1) * currval << ' ' << (pos2 + 1) * nval << '\n'; */
      ans -= pfs[pos2] - pfs[pos1];
      /* cout << pfs[pos2] - pfs[pos1] << '\n'; */
    }
    /* cout << ans << '\n' << '\n'; */
    cout << ans << '\n';
  }
}
