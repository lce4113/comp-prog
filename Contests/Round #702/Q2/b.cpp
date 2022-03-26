// ––– CodeForces Round #702: Problem B –––

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

int b[3];

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      b[x % 3]++;
    }
    int c = n / 3;

    for (int i = 0; i < 3; i++) {
      b[i] -= c;
    }

    int ans = 0, B = true;
    for (int i = 0;; i++) {
      if (i % 3 == 0) {
        if (!B) {
          break;
        }
        B = false;
      }
      if (b[i % 3] > 0) {
        b[(i + 1) % 3] += b[i % 3];
        ans += b[i % 3];
        b[i % 3] = 0;
        B = true;
      } else if (b[i % 3] != 0) {
        B = true;
      }
    }

    cout << ans << '\n';
  }
}
