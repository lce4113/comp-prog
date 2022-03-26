// ––– CodeForces Round #629: Problem C –––

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

    char a[n], b[n];
    bool B = false;
    for (int i = 0; i < n; i++) {
      char x;
      cin >> x;
      if (x == '0') {
        a[i] = '0', b[i] = '0';
      } else if (x == '1') {
        if (B) {
          a[i] = '1', b[i] = '0';
        } else {
          a[i] = '0', b[i] = '1';
        }
        B = true;
      } else if (B) {
        a[i] = '2', b[i] = '0';
      } else {
        a[i] = '1', b[i] = '1';
      }
    }

    for (auto& x : a) {
      cout << x;
    }
    cout << '\n';

    for (auto& x : b) {
      cout << x;
    }
    cout << '\n';
  }
}
