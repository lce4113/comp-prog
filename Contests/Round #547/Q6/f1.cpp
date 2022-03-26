// ––– CodeForces Round #547: Problem F1 –––

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

  int a[n + 1];
  a[0] = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i + 1] = a[i] + x;
  }

  map<int, vector<pi>> b;
  for (int i = 0; i <= n; i++) {
    for (int k = i + 1; k <= n; k++) {
      b[a[k] - a[i]].pb({ k, i });
    }
  }

  vector<pi> ans;
  for (auto& x : b) {
    vector<pi> y = x.s, c;
    int n = y.size(), d = -1;
    sort(y.begin(), y.end());
    for (int i = 0; i < n; i++) {
      if (y[i].s >= d) {
        d = y[i].f;
        c.pb({ y[i].s, y[i].f });
      }
    }
    if (c.size() > ans.size()) {
      ans = c;
    }
  }

  cout << ans.size() << '\n';
  for (auto& x : ans) {
    cout << x.f + 1 << ' ' << x.s << '\n';
  }
  cout << '\n';
}
