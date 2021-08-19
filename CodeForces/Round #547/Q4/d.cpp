// ––– CodeForces Round #547: Problem D –––

#include <bits/stdc++.h>
using namespace std;

// Data Type Shortcuts

using str = string;
using ll = long long;
using db = double;
using ld = long double;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<str>;
using vl = vector<ll>;
using mp = map<int, int>;
using mset = multiset<int>;
using pq = priority_queue<int>;
using rpq = priority_queue<int, vi, greater<int>>;
using dq = deque<int>;

// Other Shortcuts

#define f first
#define s second
#define pb push_back
#define pf push_front

// Functions

#define eq(a, b, eps) (abs(a - b) < eps)

#define init(arr)                               \
  {                                             \
    int arrSize = sizeof(arr) / sizeof(arr[0]); \
    for (int i = 0; i < arrSize; i++) {         \
      arr[i] = 0;                               \
    }                                           \
  }

// ––– CODE –––

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  str a, b;
  cin >> a >> b;

  vi g, h;
  map<char, vi> d;
  map<char, int> c;
  for (int i = 0; i < n; i++) {
    if (a[i] == '?') {
      g.pb(i);
    }
    if (b[i] == '?') {
      h.pb(i);
      continue;
    }
    d[b[i]].pb(i);
    c[b[i]] = 0;
  }

  set<int> e, f;
  vector<pi> ans;
  for (int i = 0; i < n; i++) {
    if (d.count(a[i])) {
      if (c[a[i]] >= d[a[i]].size()) {
        continue;
      }
      if (e.count(i) || f.count(d[a[i]][c[a[i]]])) {
        continue;
      }
      ans.pb({ i, d[a[i]][c[a[i]]] });
      e.insert(i);
      f.insert(d[a[i]][c[a[i]]]);
      c[a[i]]++;
    }
  }

  int k = 0;
  if (h.size()) {
    while (f.count(h[k]) && k < h.size()) {
      k++;
    }
  }
  for (int i = 0; i < n && k < h.size(); i++) {
    if (!e.count(i) && a[i] != '?') {
      ans.pb({ i, h[k] });
      e.insert(i);
      f.insert(h[k]);
      while (f.count(h[k]) && k < h.size()) {
        k++;
      }
    }
  }

  k = 0;
  if (g.size()) {
    while (e.count(g[k]) && k < g.size()) {
      k++;
    }
  }
  for (int i = 0; i < n && k < g.size(); i++) {
    if (!f.count(i) && a[i] != '?') {
      ans.pb({ g[k], i });
      e.insert(g[k]);
      f.insert(i);
      while (e.count(g[k]) && k < g.size()) {
        k++;
      }
    }
  }

  for (int i = 0, k = 0; i < n && k < n; i++, k++) {
    while (i < n && (e.count(i) || a[i] != '?')) {
      i++;
    }
    while (k < n && (f.count(k) || a[k] != '?')) {
      k++;
    }
    if (i < n && k < n) {
      ans.pb({ i, k });
    }
  }

  cout << ans.size() << '\n';
  for (auto& x : ans) {
    cout << x.f + 1 << ' ' << x.s + 1 << '\n';
  }
  cout << '\n';
}
