// ––– LIT 2020 Standard: Problem B –––

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

const int MAXN = 1e3 + 5;
const int MOD = 1e9 + 7;

mset R, B;
ll ans = 0;
int r, b, s;

void f(vi a, int n, int RorB, int sm)
{
  if (sm == s) {
    ans++;
    ans %= MOD;
    return;
  } else if (sm > s) {
    return;
  }

  a.pb(n);
  if (RorB && a.size() % 2 || !RorB && a.size() % 2 == 0) {
    for (auto& it = --R.upper_bound(n); it != R.begin(); --it) {
      /* cout << n << ' ' << *it << '\n'; */
      f(a, *it, RorB, sm + *it);
    }
    /* cout << *R.begin() << ' ' << n << '\n'; */
    if (*R.begin() <= n) {
      /* cout << n << ' ' << *R.begin() << '\n'; */
      f(a, *R.begin(), RorB, sm + *R.begin());
    }
  } else {
    for (auto& it = --B.upper_bound(n); it != B.begin(); --it) {
      /* cout << n << ' ' << *it << '\n'; */
      f(a, *it, RorB, sm + *it);
    }
    /* cout << *B.begin() << ' ' << n << '\n'; */
    if (*B.begin() <= n) {
      /* cout << n << ' ' << *B.begin() << '\n'; */
      f(a, *B.begin(), RorB, sm + *B.begin());
    }
  }
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  cin >> r >> b >> s;

  for (int i = 0; i < r; i++) {
    int x;
    cin >> x;
    R.insert(x);
  }

  for (int i = 0; i < b; i++) {
    int x;
    cin >> x;
    B.insert(x);
  }

  vi a;
  f(a, *R.rbegin(), 0, *R.rbegin());
  f(a, *B.rbegin(), 1, *B.rbegin());

  cout << ans << '\n';
}
