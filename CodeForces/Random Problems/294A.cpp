// ––– CodeForces Contest 294, Problem A: "Shaass Oskols" –––

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

  int n;
  cin >> n;

  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[i] = x;
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int x;
    int y;
    cin >> x >> y;
    if (x < n) {
      a[x + 1] += a[x] - y;
    }
    if (x - 1 >= 0) {
      a[x - 1] += y - 1;
    }
    a[x] = 0;
  }

  for (int i = 1; i <= n; i++) {
    cout << a[i] << '\n';
  }
}
