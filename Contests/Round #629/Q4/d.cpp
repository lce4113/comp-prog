// ––– CodeForces Round #629: Problem D –––

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
    set<int> b;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[i] = x;
      b.insert(x);
    }

    int B = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] == a[(i + 1) % n]) {
        B = i + 1;
      }
    }

    if (b.size() == 1) {
      cout << 1 << '\n';
      for (int i = 0; i < n; i++) {
        cout << 1 << ' ';
      }
      cout << '\n';
      continue;
    }

    if (n % 2) {
      if (B == -1) {
        cout << 3 << '\n';
        for (int i = 0; i < n - 1; i++) {
          cout << (i % 2 ? 1 : 2) << ' ';
        }
        cout << 3 << ' ';
        cout << '\n';
      } else {
        cout << 2 << '\n';
        int c = 1;
        for (int i = 0; i < n; i++) {
          if (i == B) {
            cout << c << ' ';
            continue;
          }
          c = 3 - c;
          cout << c << ' ';
        }
        cout << '\n';
      }
    } else {
      cout << 2 << '\n';
      for (int i = 0; i < n; i++) {
        cout << (i % 2 ? 1 : 2) << ' ';
      }
      cout << '\n';
    }
  }
}
