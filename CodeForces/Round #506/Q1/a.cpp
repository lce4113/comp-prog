// ––– CodeForces Round #506: Problem A –––

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

  int n, k;
  cin >> n >> k;

  str a;
  cin >> a;

  int x = 0;
  for (int i = 0; i < (n == 1 ? 0 : n - 1); i++) {
    if (a.substr(0, i + 1) == a.substr(n - i - 1, i + 1)) {
      x = i + 1;
    }
  }

  str ans = a;
  for (int i = 0; i < k - 1; i++) {
    ans += a.substr(x, n - x);
  }

  cout << ans << '\n';
}
