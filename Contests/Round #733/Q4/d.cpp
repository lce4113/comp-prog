// ––– CodeForces Round #733: Problem D –––

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

#define ins(map, elt)     \
  {                       \
    if (map.count(elt)) { \
      map[elt]++;         \
    } else {              \
      map[elt] = 1;       \
    }                     \
  }

// ––– CODE –––

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int a[n], b[n];
    map<int, vi> c;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      x--;
      a[i] = x;
      b[i] = x;
      c[x].pb(i);
    }

    vi d;
    for (int i = 0; i < n; i++) {
      if (!c.count(i)) {
        d.pb(i);
      }
    }

    int l = 0;
    for (auto& x : c) {
      for (int k = 0; k < x.s.size() - 1; k++) {
        if (d[l] == x.s[k]) {
          if (d.size() == 1) {
            int tmp = x.s[k];
            x.s[k] = x.s[k + 1];
            x.s[k + 1] = tmp;
          } else {
            cout << l << '\n';
            int tmp = d[l];
            d[l] = d[l + 1];
            d[l + 1] = tmp;
          }
        }
        a[x.s[k]] = d[l];
        l++;
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        ans++;
      }
    }

    cout << ans << '\n';
    for (auto& x : a) {
      cout << x + 1 << ' ';
    }
    cout << '\n';
  }
}
