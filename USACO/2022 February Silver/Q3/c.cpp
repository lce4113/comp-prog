#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pf push_front
#define f first
#define s second

void solve() {
  int m, n, k;
  cin >> m >> n >> k;
  /* m = 5, n = 5, k = 2; */

  vector<int> f(n), g;
  vector<vector<int>> pos(m);
  for (int i = 0; i < n; i++) {
    cin >> f[i];
    pos[--f[i]].pb(i);
  }

  int currmin = 0;
  for (int i = 0; i < n; i++) {
    if (f[i] >= currmin + k) g.pb(f[i]);
    for (int l = 0; l < k && pos[currmin].back() <= i; l++) currmin++;
  }
  reverse(g.begin(), g.end());

  for (auto &x : g) cout << x << ' ';
  cout << '\n';

  vector<vector<int>> pos2(m);
  for (int i = 0; i < g.size(); i++) {
    pos2[g[i]].pb(i);
  }

  for (auto &x : pos2) {
    cout << "- ";
    for (auto &y : x) cout << y << ' ';
    cout << '\n';
  }
  cout << '\n';

  int d = 0;
  cout << "asdf " << currmin << '\n';
  for (int i = 0; i < g.size() && currmin < m; i++) {
    /* cout << currmin << '\n'; */
    /* cout << g[i] << ' ' << currmin + k << '\n'; */
    if (g[i] > currmin + k) {
      d++;
      cout << d << ' ' << k << '\n';
      if (d >= k) {
        cout << "NO" << '\n';
        return;
      }
    }
    cout << "- ";
    for (auto &y : pos2[currmin]) cout << y << ' ';
    cout << '\n';
    for (int l = 0; l < k && pos[currmin].back() <= i; l++) currmin++;
    /* currmin++; */
  }

  /*   for (auto &x : g) cout << x << ' '; */
  /*   cout << '\n'; */

  cout << "YES" << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
