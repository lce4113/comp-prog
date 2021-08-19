// ––– CodeForces Contest 1391, Problem B: "Fix You" –––

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

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    char a[n][m];
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < m; k++) {
        char x;
        cin >> x;
        a[i][k] = x;
      }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
      if (a[n - 1][i] == 'D') {
        ans++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (a[i][m - 1] == 'R') {
        ans++;
      }
    }

    cout << ans << '\n';
  }
}
