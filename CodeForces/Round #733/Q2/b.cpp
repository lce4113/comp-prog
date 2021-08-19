// ––– CodeForces Round #733: Problem B –––

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
    int h, w;
    cin >> h >> w;

    int a[h][w];
    for (int i = 0; i < h; i++) {
      for (int k = 0; k < w; k++) {
        a[i][k] = 0;
      }
    }

    for (int i = 0; i < w; i += 2) {
      a[0][i] = 1;
      a[h - 1][i] = 1;
    }

    for (int i = 2; i < h - 2; i += 2) {
      a[i][0] = 1;
      a[i][w - 1] = 1;
    }

    for (auto& x : a) {
      for (auto& y : x) {
        cout << y;
      }
      cout << '\n';
    }
    cout << '\n';
  }
}
