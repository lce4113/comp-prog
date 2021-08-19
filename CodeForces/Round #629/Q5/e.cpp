// ––– CodeForces Round #629: Problem E –––

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

  int n, m;
  cin >> n >> m;

  pair<int, int> a[n - 1];
  for (int i = 0; i < n - 1; i++) {
    int x;
    int y;
    cin >> x >> y;
    a[i] = {x, y};
  }

  while (m--) {
    int k;
    cin >> k;

    int b[k];
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      b[i] = x;
    }


  }
}
