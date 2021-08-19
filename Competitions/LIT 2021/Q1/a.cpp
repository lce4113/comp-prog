// ––– LIT 2021: Problem A –––

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

signed main()
{
  cin.tie(0)->sync_with_stdio(0);

  int n, m, o;
  cin >> n >> m >> o;

  int a[n][m];
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < m; k++) {
      int x;
      cin >> x;
      a[i][k] = x;
    }
  }

  int ans = 0;
  while (o--) {
    int ms = -1, ma, mb, mc, mx;

    int curr, curra, currb, currc;
    for (int i = 0; i < n; i++) {
      curr = 0, curra = -1, currb = -1, currc = i;

      for (int k = 0; k < m; k++) {
        if (a[i][k]) {
          if (curra == -1) {
            curra = k, currb = -1;
          }
          curr++;
        } else {
          if (currb == -1 && curra != -1) {
            currb = k;
            if (curr > ms) {
              ms = curr;
              ma = curra, mb = currb, mc = currc, mx = 0;
            }
            curra = -1;
          }
          curr = 0;
        }
      }

      if (curr > ms) {
        ms = curr;
        ma = curra, mb = m, mc = currc, mx = 0;
      }
    }

    if (mx) {
      for (int i = ma; i < mb; i++) {
        a[i][mc] = 0;
      }
    } else {
      for (int i = ma; i < mb; i++) {
        a[mc][i] = 0;
      }
    }

    ans += ms;
  }

  cout << ans << '\n';
}
