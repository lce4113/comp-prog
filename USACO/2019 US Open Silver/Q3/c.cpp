// USACO 2019 US Open Silver: Problem C

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;
#define ll long long
#define pb push_back
#define f first
#define s second

int32_t main() {
  ifstream cin("fenceplan.in");
  ofstream cout("fenceplan.out");

  int n, m;
  cin >> n >> m;
  /* cout << n << ' ' << m << '\n'; */
  vector<pi> a(n), b(m);
  map<int, vi> mp;
  for (auto &x : a) cin >> x.f >> x.s;
  for (auto &x : b) {
    cin >> x.f >> x.s;
    x.f--, x.s--;
    mp[x.f].pb(x.s), mp[x.s].pb(x.f);
  }

  set<int> c;
  for (int i = 0; i < n; i++) c.insert(i);
  queue<int> d;
  vector<pair<pi, pi>> fences;
  while (d.size() || c.size()) {
    if (!d.size()) {
      int x = *c.begin();
      /* cout << x << '\n'; */
      c.erase(x);
      d.push(x);
      fences.pb({{a[x].f, a[x].f}, {a[x].s, a[x].s}});
    }
    int curr = d.front();
    d.pop();
    for (auto x : mp[curr]) {
      if (!c.count(x)) continue;
      c.erase(x);
      d.push(x);
      auto &y = fences.back();
      y.f.f = min(y.f.f, a[x].f);
      y.f.s = max(y.f.s, a[x].f);
      y.s.f = min(y.s.f, a[x].s);
      y.s.s = max(y.s.s, a[x].s);
    }
  }

  int ans = INT_MAX;
  for (auto x : fences) {
    /* cout << x.f.f << ' ' << x.f.s << ' ' << x.s.f << ' ' << x.s.s << '\n'; */
    int curr = 2 * (x.f.s - x.f.f + x.s.s - x.s.f);
    ans = min(ans, curr);
  }

  cout << ans << '\n';
}
