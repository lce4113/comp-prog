#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
#define ll long long

using pi = pair<int, int>;

vector<ll> ans;
int n, xg, yg;

vector<pair<pi, map<int, ll>>> func(vector<pi> a) {
  map<pi, map<int, ll>> b;
  for (int i = 0; i < pow(2, a.size()); i++) {
    int x = i, y = 0;
    pi z = {0, 0};
    for (int k = 0; k < a.size(); k++) {
      if (x % 2) {
        y++;
        z.f += a[k].f, z.s += a[k].s;
      }
      x /= 2;
    }
    b[z][y]++;
  }

  vector<pair<pi, map<int, ll>>> c;
  for (auto &x : b) c.pb(x);
  sort(c.begin(), c.end());
  return c;
}

void solve() {
  cin >> n >> xg >> yg;

  ans.pb(0);
  vector<pi> a, b;
  for (int i = 0; i < n; i++) {
    pi x;
    cin >> x.f >> x.s;
    if (i < n / 2) {
      a.pb(x);
    } else {
      b.pb(x);
    }
    ans.pb(0);
  }

  vector<pair<pi, map<int, ll>>> c = func(a), d = func(b);
  sort(c.begin(), c.end()), sort(d.begin(), d.end());

  for (int i = 0, k = d.size() - 1; i < c.size() && k >= 0;) {
    pi e = {c[i].f.f + d[k].f.f, c[i].f.s + d[k].f.s};
    if (e.f == xg && e.s == yg) {
      for (auto &x : c[i].s) {
        for (auto &y : d[k].s) {
          ans[x.f + y.f] += x.s * y.s;
          cout << y.f << ' ';
        }
        cout << x.f << '\n';
      }
    }
    if (e.f < xg) {
      i++;
    } else {
      k--;
    }
  }

  for (int i = 1; i < n + 1; i++) cout << ans[i] << '\n';
}

int32_t main() { solve(); }

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
