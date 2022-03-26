// ––– USACO 2022 January Silver: Problem A –––

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = pair<ll, ll>;
#define f first
#define s second

/* #define int ll */

ll max(ll a, ll b) { return a > b ? a : b; }

ll exp2(ll n) {
  ll ans = 1;
  for (ll i = 0; i < n; i++) ans *= 2;
  return ans;
}

pl bin(ll num, ll total, ll mx) {
  if (num == 0) return {total, mx};
  if (num == 1) return {total + 1, mx};
  total += num % 2;
  num /= 2;
  return bin(num, total, mx + 1);
}

void solve(ll a, ll b) {
  if (a > b) {
    ll ans = 0, B = b;
    while (B < a) B *= 2, ans++;
    pl x = bin(B - a, 0, 0);
    /* cout << B - a << ' ' << x.f << ' ' << x.s << '\n'; */
    bool bl = 1;
    if (x.s <= ans) x.s = ans, bl = 0;
    ans = x.f + x.s + x.s - ans - bl;
    cout << ans << '\n';
  } else if (b > a) {
    ll ans = 0, A = a;
    while (A <= b) A *= 2, ans++;
    A /= 2, ans--;
    pl x = bin(b - A, 0, 0);
    bool bl = 1;
    if (x.s <= ans) x.s = ans, bl = 0;
    /* cout << b - A << ' ' << x.f << ' ' << x.s << ' ' << ans << '\n'; */
    ans = x.f + x.s + x.s - ans - bl;
    cout << ans << '\n';
  } else {
    cout << 0 << '\n';
  }
}

int32_t main() {
  ll t;
  cin >> t;
  /* pl a = bin(0, 0, 0), b = bin(3, 0, 0); */
  /* cout << a.f << ' ' << a.s << "  " << b.f << ' ' << b.s << '\n'; */
  while (t--) {
    ll a, b;
    cin >> a >> b;
    solve(a, b);
  }
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
