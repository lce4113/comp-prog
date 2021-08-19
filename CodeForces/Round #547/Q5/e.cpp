// ––– CodeForces Round #547: Problem E –––

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

// ––– CODE –––

#define int ll

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  int h, n;
  cin >> h >> n;

  int a[n + 1], sm = 0, mn = 0;
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[i] = a[i - 1] + x;
    if (h + a[i] <= 0) {
      cout << i << '\n';
      return 0;
    }
    sm += x;
    mn = min(mn, sm);
  }

  if (sm >= 0) {
    cout << -1 << '\n';
    return 0;
  }

  int b = ceil((ld)(h + mn) / -sm);
  int ans = b * n;
  int c = h + b * sm;

  for (int i = 1; i <= n; i++) {
    if (c + a[i] <= 0) {
      ans += i;
      cout << ans << '\n';
      return 0;
    }
  }
}
