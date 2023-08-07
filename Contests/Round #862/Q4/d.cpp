// ––– CodeForces Round #862: Problem D –––

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define pb push_back
using pi = pair<int, int>;
#define f first
#define s second

map<int, vi> al;
map<int, int> h;
vi dists;

void rec(int n, int p, int padist) {
  vector<pi> hs;
  hs.pb({0, -1});
  hs.pb({0, -1});
  for (auto x : al[n]) {
    if (x == p) continue;
    hs.pb({h[x] + 1, x});
  }
  sort(hs.rbegin(), hs.rend());
  /* for (auto x : hs) cout << x.f << ' '; */
  /* cout << '\n'; */
  for (auto x : al[n]) {
    if (x == p) continue;
    int sdist = (x == hs[0].s ? hs[1].f : hs[0].f);
    int adist = max(sdist + 1, padist + 1);
    int mxdist = max(adist, h[x]);
    /* cout << x << ' ' << sdist << ' ' << adist << ' ' << mxdist << '\n'; */
    dists.pb(mxdist);
    rec(x, n, adist);
  }
}

int hrec(int n, int p) {
  /* if (al[n].size() <= 1 && p != -1) { */
  /*   h[n] = 0; */
  /*   return 0; */
  /* } */
  int mx = 0;
  for (auto x : al[n]) {
    if (x == p) continue;
    mx = max(mx, hrec(x, n) + 1);
  }
  h[n] = mx;
  return mx;
}

int32_t main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    al[a].pb(b);
    al[b].pb(a);
  }

  hrec(1, -1);
  rec(1, -1, 0);
  /* for (auto x : h) { */
  /*   cout << x.f << ' ' << x.s << '\n'; */
  /* } */
  /* for (auto x : al) { */
  /*   cout << x.f << ": "; */
  /*   for (auto y : x.s) { */
  /*     cout << y << ' '; */
  /*   } */
  /*   cout << '\n'; */
  /* } */

  dists.pb(h[1]);
  sort(dists.begin(), dists.end());
  /* for (auto x : dists) cout << x << ' '; */
  /* cout << '\n'; */
  for (int i = 1; i <= n; i++) {
    auto x = lower_bound(dists.begin(), dists.end(), i);
    int ans = 1 + x - dists.begin();
    ans = min(ans, n);
    cout << ans << ' ';
  }
  cout << '\n';
}
