// CodeForces Round #869: Problem D

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define pb push_back
using pi = pair<int, int>;
#define f first
#define s second

vi rec(map<int, vi> e, int x, int curr, int p, vi path) {
  path.pb(curr);
  for (auto y : e[curr]) {
    if (y == p) continue;
    if (y == x) return path;
    vi path2 = rec(e, x, y, curr, path);
    if (!path2.size()) continue;
    return path2;
  }
  return {};
}

void solve() {
  int n, m;
  cin >> n >> m;
  map<int, vi> e;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    e[a].pb(b);
    e[b].pb(a);
  }
  vi fours;
  for (auto x : e) {
    if (x.s.size() >= 4) fours.pb(x.f);
  }
  for (auto x : fours) {
    vi path = rec(e, x, x, -1, {});
    if (!path.size()) continue;
    set<int> tails;
    for (auto y : e[x]) {
      if (y == path[1]) continue;
      if (y == path[path.size() - 1]) continue;
      tails.insert(y);
    }
    if (tails.size() < 2) continue;

    cout << "YES" << '\n';
    vector<pi> ans;
    /* for (auto y : path) cout << y << ' '; */
    /* cout << '\n'; */
    for (int i = 0; i < path.size(); i++) {
      ans.pb({path[i], path[(i + 1) % path.size()]});
      if (tails.count(path[(i + 1) % path.size()])) {
        ans.pb({path[(i + 1) % path.size()], x});
        tails.erase(path[(i + 1) % path.size()]);
        tails.insert(path[path.size() - 1]);
        break;
      }
    }
    ans.pb({*tails.begin(), x});
    ans.pb({*(++tails.begin()), x});
    cout << ans.size() << '\n';
    for (auto y : ans) cout << y.f << ' ' << y.s << '\n';
    return;
  }
  cout << "NO" << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
