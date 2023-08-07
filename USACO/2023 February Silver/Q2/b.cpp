// USACO 2023 February Silver: Problem B

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define int long long
#define db long double

db d(int x, int y) { return sqrt((db)(x * x + y * y)); }

int32_t main() {
  int g, n;
  cin >> g >> n;
  map<int, pair<int, int>> gr;
  for (int i = 0; i < g; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    gr[t] = {x, y};
  }
  /* for (auto x : gr) cout << x.f << ' ' << x.s.f << ' ' << x.s.s << '\n'; */
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    if (t <= gr.begin()->f) {
      auto p = gr.begin()->s;
      db dist = d(p.f - x, p.s - y);
      int time = gr.begin()->f - t;
      /* cout << dist << ' ' << time << '\n'; */
      if (dist > time) {
        /* cout << 1 << '\n'; */
        ans++;
      } else {
        /* cout << 0 << '\n'; */
      }
      continue;
    }
    if (t >= gr.rbegin()->f) {
      auto p = gr.rbegin()->s;
      db dist = d(abs(p.f - x), abs(p.s - y));
      int time = t - gr.rbegin()->f;
      /* cout << dist << ' ' << time << '\n'; */
      if (dist > time) {
        /* cout << 1 << '\n'; */
        ans++;
      } else {
        /* cout << 0 << '\n'; */
      }
      continue;
    }
    auto l = *(--gr.ub(t)), r = *gr.ub(t);
    db dist1 = d(abs(r.s.f - x), abs(r.s.s - y));
    int time1 = r.f - t;
    db dist2 = d(abs(l.s.f - x), abs(l.s.s - y));
    int time2 = t - l.f;
    /* cout << dist1 << ' ' << time1 << '\n'; */
    /* cout << dist2 << ' ' << time2 << '\n'; */
    if (dist1 > time1 || dist2 > time2) {
      /* cout << 1 << '\n'; */
      ans++;
    } else {
      /* cout << 0 << '\n'; */
    }
  }
  cout << ans << '\n';
}
