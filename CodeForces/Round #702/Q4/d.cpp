// ––– CodeForces Round #702: Problem D –––

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

const int MAXN = 101;

int n;
int ans[MAXN];
int a[MAXN];

void g(int l, int r, int k)
{
  if (r - l <= 0) {
    return;
  }

  int mx = l;
  for (int i = l; i < r; i++) {
    if (a[i] > a[mx]) {
      mx = i;
    }
  }

  ans[mx] = k;

  g(l, mx, k + 1);
  g(mx + 1, r, k + 1);
}

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[i] = x;
    }

    g(0, n, 0);

    for (int i = 0; i < n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}
