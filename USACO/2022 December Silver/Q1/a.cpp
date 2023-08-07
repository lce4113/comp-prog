// ––– USACO 2022 December Silver: Problem A –––

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> barns;
map<ll, set<ll>> roads;

pair<ll, vector<array<ll, 3>>> rec(ll p, ll b) {
  set<ll> as = roads[b];
  ll sumh = barns[b];
  vector<array<ll, 3>> cn, cp, d, e, ret;
  for (ll a : as) {
    if (a == p) continue;
    auto x = rec(b, a);
    sumh += x.first;
    if (x.first > 0) cp.push_back({a, b, x.first});
    if (x.first < 0) cn.push_back({b, a, -x.first});
    if (x.first >= 0)
      for (auto m : x.second) d.push_back(m);
    else
      for (auto m : x.second) e.push_back(m);
  }
  for (auto x : d) ret.push_back(x);
  for (auto x : cp) ret.push_back(x);
  for (auto x : cn) ret.push_back(x);
  for (auto x : e) ret.push_back(x);

  return {sumh, ret};
}

int main() {
  ll n;
  cin >> n;

  ll goal = 0;
  for (ll i = 0; i < n; i++) {
    ll h;
    cin >> h;
    barns.push_back(h);
    goal += h;
  }
  goal /= n;
  for (ll &h : barns) h -= goal;

  for (ll i = 0; i < n - 1; i++) {
    ll x, y;
    cin >> x >> y;
    x--, y--;
    roads[x].insert(y);
    roads[y].insert(x);
  }

  auto ans = rec(-1, 0).second;
  cout << ans.size() << '\n';
  for (auto x : ans) {
    cout << x[0] + 1 << ' ' << x[1] + 1 << ' ' << x[2] << '\n';
  }
}

/* stuff you should look for
 * ll overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

