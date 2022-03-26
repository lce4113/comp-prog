// ––– CodeForces Round #547: Problem C –––

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

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  int a[n - 1], mn = INT_MAX, mx = -1, sm = 0;
  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    sm += x;
    a[i] = sm;
    mn = min(mn, sm), mx = max(mx, sm);
  }

  int ans[n];
  set<int> b;
  if (mn == 1) {
    ans[0] = 1;
    b.insert(1);
  } else {
    ans[0] = -mn + 1;
    b.insert(-mn + 1);
  }
  if (ans[0] > n || ans[0] < 1) {
    cout << -1 << '\n';
    return 0;
  }
  for (int i = 1; i < n; i++) {
    ans[i] = a[i - 1] + ans[0];
    if (ans[i] > n || ans[i] < 1 || b.count(ans[i])) {
      cout << -1 << '\n';
      return 0;
    }
    b.insert(ans[i]);
  }

  for (auto& x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
}
