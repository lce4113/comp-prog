// ––– CodeForces Round #734: Problem C –––

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

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    mp a[n];
    int l[n];
    for (int i = 0; i < n; i++) {
      str x;
      cin >> x;
      int m = x.length();
      l[i] = m;
      for (int k = 0; k < m; k++) {
        a[i][x[k] - 'a']++;
      }
    }

    int ans = -1;
    for (int i = 0; i < 5; i++) {
      vector<pi> b;
      for (int k = 0; k < n; k++) {
        b.pb({ a[k][i], l[k] });
      }

      sort(b.begin(), b.end(), [](pi a, pi b) {
        /* double c = a.f / a.s, d = b.f / b.s; */
        /* if (c == d) { */
        /*   if (a.f == b.f) { */
        /*     return a.s < b.s; */
        /*   } */
        /*   return a.f > b.f; */
        /* } */
        /* return ((double)a.f / a.s > (double)b.f / b.s); */

        double c = 2 * a.f - a.s, d = 2 * b.f - b.s;
        /* cout << c << ' ' << d << '\n'; */
        return c > d;
      });
      /* cout << '\n'; */
      /* cout << "E" << '\n'; */
      /* cout << '\n'; */

      /*       for (auto& x : b) { */
      /*         cout << x.f << ' ' << x.s << '\n'; */
      /*       } */
      /*       cout << '\n'; */

      int c = 0, d = 0, e = 0;
      for (int k = 0; k < n; k++) {
        c += b[k].f;
        d += b[k].s;
        e++;
        if (c <= d / 2) {
          e--;
          break;
        }
      }
      ans = max(ans, e);
    }

    cout << ans << '\n';
  }
}
