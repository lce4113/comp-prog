// ––– CodeForces Round #506: Problem F –––

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

vl pf(ll n)
{
  vl ans;

  while (n % 2 == 0) {
    ans.pb(2);
    n /= 2;
  }

  for (ll i = 3; i * i <= n; i = i + 2) {
    while (n % i == 0) {
      ans.pb(i);
      n /= i;
    }
  }

  if (n > 2) {
    ans.pb(n);
  }

  return ans;
}

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  ll a, b;
  cin >> a >> b;
  ll c = a + b;

  for (ll i = sqrt(c); i > 0; i--) {
    if (c % i == 0) {
      ll x = min(i, c / i), y = max(i, c / i);
      for (ll k = x; k > 0; k--) {
        if (a % k == 0 && a / k <= y) {
          cout << (x + y) * 2 << '\n';
          return 0;
        }
      }
      for (ll k = x; k > 0; k--) {
        if (b % k == 0 && b / k <= y) {
          cout << (x + y) * 2 << '\n';
          return 0;
        }
      }
    }
  }
}
