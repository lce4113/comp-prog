// ––– CodeForces Global Round 15: Problem C –––

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

#define int ll

// ––– CODE –––

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n, z;
    cin >> n >> z;
    n *= 2;

    vector<pi> a;
    set<int> b;
    for (int i = 0; i < z; i++) {
      int x;
      int y;
      cin >> x >> y;
      if (x > y) {
        int tmp = x;
        x = y;
        y = tmp;
      }
      a.pb({ x, y });
      b.insert(x);
      b.insert(y);
    }

    int ans = 0;
    for (int i = 0; i < z; i++) {
      for (int k = i + 1; k < z; k++) {
        int y = 0;
        if (a[i].f < a[k].s && a[k].s < a[i].s) {
          y++;
        }
        if (a[i].f < a[k].f && a[k].f < a[i].s) {
          y++;
        }
        if (y == 1) {
          ans++;
        }
      }
    }

    for (int i = 0; i < z; i++) {
      int l = 0, r = 0;
      for (int k = 1; k <= n; k++) {
        if (b.count(k)) {
          continue;
        }

        if (a[i].f < k && k < a[i].s) {
          l++;
        } else {
          r++;
        }
      }
      ans += min(l, r);
    }

    int x = 0;
    for (int i = 1; i <= n; i++) {
      if (!b.count(i)) {
        x++;
      }
    }
    x /= 2;

    ans += x * (x - 1) / 2;

    cout << ans << '\n';
  }
}
