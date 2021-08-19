// ––– CodeForces Round #702: Problem G –––

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

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    int sm = 0;
    vi a;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      sm += x;
      for (int k = a.size(); k < sm; k++) {
        a.pb(i);
      }
    }

    for (auto& x : a) {
      cout << x << ' ';
    }
    cout << '\n';

    /*     cout << '\n'; */
    /*     for (auto& x : a) { */
    /*       cout << x.f << ' ' << x.s << '\n'; */
    /*     } */
    /*     cout << '\n'; */

    /*     while (m--) { */
    /*       int x; */
    /*       cin >> x; */

    /*       cout << x / sm * n + a[x % sm] - 1 << ' '; */
    /*     } */
    /*     cout << '\n'; */
  }
}
