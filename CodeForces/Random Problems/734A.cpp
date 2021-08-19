// ––– https://codeforces.com/contest/734/problem/A - "Anton and Danik" –––

// TEMPLATE {{{

#include <bits/stdc++.h>
using namespace std;

// Data Type Aliases

using str = string;
using ll = long long;
using db = long double;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<str>;
using vl = vector<ll>;
using vd = vector<db>;

using mp = map<int, int>;
using mset = multiset<int>;
using pq = priority_queue<int>;
using rpq = priority_queue<int, vi, greater<int>>;
using dq = deque<int>;

#define tcT template <class T>
#define tcTU template <class T, class U>
#define tcTS template <class T, int SZ>
tcT using V = vector<T>;
tcTS using A = array<T, SZ>;
tcTU using P = pair<T, U>;
tcT using S = set<T>;
tcTU using M = map<T, U>;
tcTU using MS = multiset<T>;
tcT using PQ = priority_queue<T>;
tcT using RPQ = priority_queue<T, vi, greater<T>>;
tcT using DQ = deque<T>;

// Macros

#define f first
#define s second
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound

// Functions

#define eq(a, b, eps) (abs(a - b) < eps)

#define swap(a, b) \
  {                \
    auto tmp = a;  \
    a = b;         \
    b = tmp;       \
  }

#define init(arr)                               \
  {                                             \
    int arrSize = sizeof(arr) / sizeof(arr[0]); \
    for (int i = 0; i < arrSize; i++) {         \
      arr[i] = 0;                               \
    }                                           \
  }

// For Loops

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto& a : x)

// Constants

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const db PI = acos((db)-1);
const int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 }; // for every grid problem!!

// }}}

// ––– CODE –––

#define int ll

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  int b = 0;
  vc a(n);
  for (auto& x : a) {
    cin >> x;
    b += (x == 'A');
    b -= (x == 'D');
  }

  if (b == 0) {
    cout << "Friendship" << '\n';
  } else if (b > 0) {
    cout << "Anton" << '\n';
  } else {
    cout << "Danik" << '\n';
  }
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
