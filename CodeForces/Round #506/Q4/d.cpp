// ––– CodeForces Round #506: Problem D –––

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

#define int ll

int pow10(int n)
{
  int ans = 1;
  for (int i = 0; i < n; i++) {
    ans *= 10;
  }
  return ans;
}

int len(int n)
{
  int ans = 0;
  while (n) {
    n /= 10;
    ans++;
  }
  return ans;
}

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  int mod10[10], curr = 1;
  for (int i = 0; i < 10; i++) {
    curr *= 10;
    curr %= m;
    mod10[i] = curr;
  }

  int a[n], b[n], c[n];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = x % m;
    b[i] = (m - a[i]) % m;
    c[i] = len(x) - 1;
  }

  mp d[10];
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < 10; k++) {
      int x = (a[i] * mod10[k]) % m;
      d[k][x]++;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += d[c[i]][b[i]];
  }

  for (int i = 0; i < n; i++) {
    int x = a[i] * mod10[c[i]] + a[i];
    if (x % m == 0) {
      ans--;
    }
  }

  cout << ans << '\n';

  /*   int ans2 = 0; */
  /*   for (int i = 0; i < n; i++) { */
  /*     for (int k = 0; k < n; k++) { */
  /*       if (i == k) { */
  /*         continue; */
  /*       } */
  /*       int x = a[i] * pow10((int)log10(a[k])) + a[k]; */
  /*       cout << a[i] << ' ' << a[k] << ' ' << x << '\n'; */
  /*       if (x % m == 0) { */
  /*         ans2++; */
  /*       } */
  /*     } */
  /*   } */

  /*   cout << ans2 << '\n'; */
}
