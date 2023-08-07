// CodeForces Educational Round 146: Problem E

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
  n--;
  vi a(n);
  for (auto &x : a) cin >> x;

  int sm = 0;
  for (auto x : a) sm += x;
  /* cout << sm << '\n'; */

  vi k(n, 0);
  k[0] = 0, k[1] = a[1], k[2] = max(a[1], a[2]);
  for (int i = 3; i < n - 1; i++) {
    k[i] = max(k[i], k[i - 1]);
    k[i] = max(k[i], k[i - 2] + a[i]);
    k[i] = max(k[i], k[i - 3] + a[i]);
  }
  k[n - 1] = k[n - 2];
  /* for (auto x : k) cout << x << ' '; */
  /* cout << '\n'; */

  vi rk(n, 0);
  rk[n - 1] = 0, rk[n - 2] = a[n - 2], rk[n - 3] = max(a[n - 2], a[n - 3]);
  for (int i = n - 4; i >= 1; i--) {
    rk[i] = max(rk[i], rk[i + 1]);
    rk[i] = max(rk[i], rk[i + 2] + a[i]);
    rk[i] = max(rk[i], rk[i + 3] + a[i]);
  }
  rk[0] = rk[1];
  /* for (auto x : rk) cout << x << ' '; */
  /* cout << '\n'; */

  int q;
  cin >> q;
  while (q--) {
    int p, x;
    cin >> p >> x;
    p--;
    int nsm = sm - a[p] + x;
    int l1 = (p < 2 ? 0 : k[p - 2]);
    int r1 = (p > n - 3 ? 0 : rk[p + 2]);
    int l2 = (p < 1 ? 0 : k[p - 1]);
    int r2 = (p > n - 2 ? 0 : rk[p + 1]);
    cout << l1 << ' ' << r1 << ' ' << x << ' ' << l2 << ' ' << r2 << '\n';
    int mx = max(l1 + r1 + x, l2 + r2);
    int ans = (nsm - mx) * 2;
    cout << ans << '\n';
  }
}
