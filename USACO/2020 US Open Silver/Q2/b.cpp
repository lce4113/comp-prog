// USACO 2020 US Open Silver: Problem B

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pi = pair<int, int>;
#define pb push_back
#define f first
#define s second

int n, m;
vector<pi> a;
map<int, pi> store;
set<int> curr;
vi ans;

void add(int x, int i, int fir) {
  /* cout << x << ' ' << i << ' ' << fir << '\n'; */
  if (!store[x].f) {
    curr.insert(x);
    store[x] = {i, fir ? a[i].s : -1};
    return;
  }
  if (i > store[x].f) return;
  if (store[x].s == -1) {
    store[x] = {i, fir ? a[i].s : -1};
    return;
  }
  add(store[x].s, store[x].f, 0);
  store[x] = {i, fir ? a[i].s : -1};
}

int32_t main() {
  ifstream cin("cereal.in");
  ofstream cout("cereal.out");

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    pi x;
    cin >> x.f >> x.s;
    a.pb(x);
  }
  for (int i = n - 1; i >= 0; i--) {
    /* cout << a[i].f << ' ' << a[i].s << '\n'; */
    /* cout << store[a[i].f].f << ' ' << store[a[i].f].s << '\n'; */
    add(a[i].f, i, 1);
    /* for (auto x : curr) cout << x << ' '; */
    /* cout << '\n' << '\n'; */
    ans.pb(curr.size());
  }

  for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << '\n';
}
