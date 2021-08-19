// ––– USACO 2021 February Silver: Problem C –––

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

#define int ll

const int MAXN = 505;

int n, a[MAXN][MAXN];

int f(int x)
{
  int ans = 0;

  for (int i = 0; i < n; i++) {
    int m[n];
    for (int k = 0; k < n; k++) {
      m[k] = -1;
      for (int l = i; l >= 0; l--) {
        if (a[l][k] < x) {
          m[k] = l;
          break;
        }
      }

      for (int l = 0; l < k; l++) {
        m[l] = max(m[l], m[k]);
      }

      int asdf = 0;
      for (int l = 0; l <= k; l++) {
        asdf += (i - m[l]);
      }

      ans += asdf;
    }
  }

  return ans;
}

signed main()
{
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      int x;
      cin >> x;
      a[i][k] = x;
    }
  }

  int ans = f(100) - f(101);
  cout << ans << '\n';
}
