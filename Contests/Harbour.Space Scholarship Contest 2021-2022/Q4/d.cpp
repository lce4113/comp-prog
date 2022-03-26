// ––– CodeForces Harbour.Space Scholarship Contest 2021-2022: Problem D –––

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

  int t;
  cin >> t;
  while (t--) {
    str a, b;
    cin >> a >> b;
    int n = a.length(), m = b.length();

    if (m > n) {
      cout << "NO" << '\n';
      continue;
    }

    for (int i = n - 1, k = m - 1; i >= 0; i--) {
      if (a[i] == b[k]) {
        k--;
      } else {
        i--;
      }
      if (k < 0) {
        goto done;
      }
    }

    cout << "NO" << '\n';
    continue;
  done:
    cout << "YES" << '\n';
  }
}
