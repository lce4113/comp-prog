// ––– USACO 2022 US Open Silver: Problem A –––

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
using vl = vector<ll>;
using pl = pair<ll, ll>;

void solve() {
  ll n;
  cin >> n;

  vector<pl> a(n);
  set<ll> b;
  for (ll i = 0; i < n; i++) {
    cin >> a[i].f >> a[i].s;
    a[i].f--;
    b.insert(i);
  }

  ll ans = 0, curr = 0;
  while (b.size()) {
    ll x = *b.begin(), y = x, sum = 0, mn = 1e9;
    set<ll> p;
    do {
      b.erase(y);
      p.insert(y);
      y = a[y].f;
      sum += a[y].s;
      mn = min(mn, a[y].s);
    } while (b.count(y));
    if (p.count(y)) {
      sum -= mn;
      ans += curr;
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
