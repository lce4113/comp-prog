// ––– CodeForces Round #642: Problem B –––

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

#define init(arr)                               \
  {                                             \
    int arrSize = sizeof(arr) / sizeof(arr[0]); \
    for (int i = 0; i < arrSize; i++) {         \
      arr[i] = 0;                               \
    }                                           \
  }

#define ins(map, elt)     \
  {                       \
    if (map.count(elt)) { \
      map[elt]++;         \
    } else {              \
      map[elt] = 1;       \
    }                     \
  }

// ––– CODE –––

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    rpq a;
    pq b;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.push(x);
    }

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      b.push(x);
    }

    for (int i = 0; i < k; i++) {
      int A = a.top();
      int B = b.top();

      if (A > B) {
        break;
      }

      a.pop();
      b.pop();
      a.push(B);
      b.push(A);
    }

    int ans = 0;
    while (a.size()) {
      ans += a.top();
      a.pop();
    }

    cout << ans << '\n';
  }
}
