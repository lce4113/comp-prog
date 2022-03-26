// ––– CodeForces Harbour.Space Scholarship Contest 2021-2022: Problem C –––

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

str a;

int f(int i, int b, int c)
{
  if (i == 10) {
    return 10;
  }

  if (b > c) {
    if (b - c > (10 - i) / 2) {
      return i;
    }
  } else {
    if (c - b > (i % 2 ? (11 - i) / 2 : (10 - i) / 2)) {
      return i;
    }
  }

  if (a[i] == '?') {
    if (i % 2) {
      return min(f(i + 1, b + 1, c), f(i + 1, b, c));
    } else {
      return min(f(i + 1, b, c + 1), f(i + 1, b, c));
    }
  } else if (a[i] == '1') {
    if (i % 2) {
      return f(i + 1, b + 1, c);
    } else {
      return f(i + 1, b, c + 1);
    }
  } else {
    return f(i + 1, b, c);
  }
}

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> a;

    int ans = f(0, 0, 0);
    cout << ans << '\n';
  }
}
