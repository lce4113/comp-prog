// ––– CodeForces Round #733: Problem C –––

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
    int n;
    cin >> n;

    int g = n - n / 4;

    vi a;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.pb(x);
    }

    sort(a.begin(), a.end());
    int sm1 = 0;
    for (int i = n - g; i < n; i++) {
      sm1 += a[i];
    }

    vi b;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      b.pb(x);
    }

    sort(b.begin(), b.end());
    int sm2 = 0;
    for (int i = n - g; i < n; i++) {
      sm2 += b[i];
    }

    int ans = 0, i = n - g, k = n - g - 1;
    while (sm2 > sm1) {
      sm1 += 100;
      if (++n % 4 == 0) {
        sm1 -= a[i];
        i++;
      } else if (k >= 0) {
        sm2 += b[k];
        k--;
      }
      ans++;
    }

    cout << ans << '\n';
  }
}
