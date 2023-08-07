// USACO 2020 January Silver: Problem C

#include <bits/stdc++.h>
using namespace std;

/* #define int long long */

using vi = vector<int>;
#define pb push_back
using pi = pair<int, int>;
#define f first
#define s second

int32_t main() {
  ifstream cin("wormsort.in");
  ofstream cout("wormsort.out");

  int n, m;
  cin >> n >> m;
  vi cows(n);
  for (auto &c : cows) {
    cin >> c;
    c--;
  }
  map<int, vector<pi>> wormholes;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    wormholes[a].pb({c, b});
    wormholes[b].pb({c, a});
  }

  vector<set<int>> cycles;
  set<int> remaining;
  for (int i = 0; i < n; i++) remaining.insert(i);
  while (remaining.size()) {
    set<int> cycle;
    int start = *remaining.begin();
    int curr = cows[start];
    cycle.insert(curr);
    remaining.erase(curr);
    while (curr != start) {
      curr = cows[curr];
      cycle.insert(curr);
      remaining.erase(curr);
    }
    cycles.pb(cycle);
  }

  /*   for (auto x : wormholes) { */
  /*     cout << x.f << ": "; */
  /*     for (auto y : x.s) { */
  /*       cout << y.f << ' ' << y.s << ", "; */
  /*     } */
  /*     cout << '\n'; */
  /*   } */

  int ans = INT_MAX;
  for (auto &c : cycles) {
    priority_queue<pair<pi, int>> q;
    for (auto x : wormholes[*c.begin()]) q.push({x, *c.begin()});
    c.erase(*c.begin());
    /* cout << q.top().f << ' ' << q.top().s << ", "; */
    while (c.size()) {
      auto curr = q.top();
      q.pop();
      c.erase(curr.f.s);
      ans = min(ans, curr.f.f);
      for (auto x : wormholes[curr.f.s]) {
        if (x.s == curr.s) continue;
        q.push({x, curr.f.s});
      }
    }
  }

  if (ans == INT_MAX) ans = -1;
  cout << ans << '\n';
}
