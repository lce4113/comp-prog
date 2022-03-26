// ––– CodeForces Round #702: Problem A –––

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
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[i] = x;
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
      int b = a[i], c = a[i - 1];
      if (c < b) {
        int tmp = b;
        b = c;
        c = tmp;
      }
      if (b != c) {
        ans--;
      }
      while (b < c) {
        ans++;
        b *= 2;
      }
    }

    cout << ans << '\n';
  }
}
