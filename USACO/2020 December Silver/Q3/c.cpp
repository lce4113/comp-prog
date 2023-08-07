// USACO 2020 December Silver: Problem C

#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
#define f first
#define s second
using vi = vector<int>;
#define pb push_back

map<int, vi> stopped;
map<int, int> dp;
int rec(int c) {
  if (dp.count(c)) return dp[c];
  if (stopped.count(c) == 0) {
    dp[c] = 0;
    return 0;
  }
  int ans = 0;
  for (auto x : stopped[c]) ans += rec(x) + 1;
  dp[c] = ans;
  return ans;
}

bool cmp(pair<pi, int> a, pair<pi, int> b) {
  if (a.f.s == b.f.s) return a.f.f < b.f.f;
  return a.f.s < b.f.s;
}
int32_t main() {
  int n;
  cin >> n;
  vector<pair<pi, int>> north, east;
  for (int i = 0; i < n; i++) {
    char dir;
    pi x;
    cin >> dir >> x.f >> x.s;
    if (dir == 'E') {
      east.pb({x, i});
    } else {
      north.pb({x, i});
    }
  }
  sort(east.begin(), east.end(), cmp);
  sort(north.begin(), north.end());
  /* for (auto x : east) cout << x.f.f << ' ' << x.f.s << ' ' << x.s << '\n'; */
  /* for (auto x : north) cout << x.f.f << ' ' << x.f.s << ' ' << x.s << '\n';
   */

  set<int> stoppedE;
  for (int i = 0; i < north.size(); i++) {
    for (int k = 0; k < east.size(); k++) {
      /* cout << north[i].s << ' ' << east[k].s << '\n'; */
      if (stoppedE.count(east[k].s)) continue;
      int timeE = north[i].f.f - east[k].f.f;
      int timeN = east[k].f.s - north[i].f.s;
      if (timeE < 0 || timeN < 0) continue;
      if (timeE == timeN) continue;
      /* cout << north[i].s << ' ' << east[k].s << '\n'; */
      if (timeE < timeN) {
        stopped[east[k].s].pb(north[i].s);
        /* cout << north[i].s << '\n'; */
        break;
      }
      stopped[north[i].s].pb(east[k].s);
      stoppedE.insert(east[k].s);
    }
    /* for (auto x : stoppedE) cout << x << ' '; */
    /* cout << '\n'; */
  }

  /* for (auto x : stopped) { */
  /*   cout << x.f << ": "; */
  /*   for (auto y : x.s) cout << y << ' '; */
  /*   cout << '\n'; */
  /* } */

  for (int i = 0; i < n; i++) {
    int ans = rec(i);
    cout << ans << '\n';
  }
}
