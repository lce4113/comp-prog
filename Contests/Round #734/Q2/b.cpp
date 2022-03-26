// ––– CodeForces Round #734: Problem B –––

// TEMPLATE {{{

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

// }}}

// ––– CODE –––

bool comp(vi a, vi b)
{
  return a.size() > b.size();
}

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    map<int, vi> m;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      m[x].pb(i);
    }

    priority_queue<vi, vector<vi>, function<bool(vi, vi)>> b(comp);
    for (auto& x : m) {
      b.push(x.s);
    }

    priority_queue<vi, vector<vi>, function<bool(vi, vi)>> g = b;
    while (g.size()) {
      for (auto& x : g.top()) {
        cout << x << ' ';
      }
      cout << '\n';
      g.pop();
    }
    cout << '\n';

    while (b.top().size() < k) {
      vi c = b.top();
      b.pop();
      vi d = b.top();
      b.pop();

      c.insert(c.end(), d.begin(), d.end());
      b.push(c);
    }

    int ans[n];
    for (int i = 0; i < n; i++) {
      ans[i] = 0;
    }

    while (b.size()) {
      vi c = b.top();
      b.pop();

      for (int i = 0; i < k; i++) {
        ans[c[i]] = i + 1;
      }
    }

    for (auto& x : ans) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}
