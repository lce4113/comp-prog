// ––– CodeForces Harbour.Space Scholarship Contest 2021-2022: Problem B –––

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

    str c = b;
    reverse(c.begin(), c.end());
    int n = a.length(), m = b.length();
    for (int i = 0; i < m; i++) {
      int B1 = -1, B2 = -1;
      for (int k = 0; k < n - i + 1; k++) {
        str d = a.substr(k, i), e = b.substr(0, i);
        if (d == e) {
          B1 = k;
          if (k + i - (m - i) + 1 < 0 || k + i - (m - i) + 1 >= n) {
            continue;
          }
          str g = a.substr(k + i - (m - i) + 1, m - i);
          str h = c.substr(0, m - i);
          if (g == h) {
            goto done;
          }
        }
      }
    }

    cout << "NO" << '\n';
    continue;
  done:
    cout << "YES" << '\n';
  }
}
