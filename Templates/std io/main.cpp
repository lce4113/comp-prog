// ––– HEADER –––

// TEMPLATE {{{

#include <bits/stdc++.h>
using namespace std;

// Data Type Aliases {{{

#define tcT template <class T>
#define tcTU template <class T, class U>
#define tcTS template <class T, int SZ>
#define tcS template <int SZ>

tcT using V = vector<T>;
tcTS using A = array<T, SZ>;
tcS using AR = array<int, SZ>;
tcTU using P = pair<T, U>;
tcT using S = set<T>;
tcTU using M = map<T, U>;
tcT using MS = multiset<T>;
tcT using PQ = priority_queue<T>;
tcTU using PQU = priority_queue<T,V<T>,U>;
tcT using RPQ = priority_queue<T, V<T>, greater<T>>;
tcT using DQ = deque<T>;

// }}}

// Common Data Type Aliases {{{

using str = string;
using ll = long long;
using db = long double;

using pi = P<int, int>;
using pl = P<ll, ll>;
using pd = P<db, db>;

using vi = V<int>;
using vb = V<bool>;
using vc = V<char>;
using vs = V<str>;
using vl = V<ll>;
using vd = V<db>;
using vp = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;
using vv = V<vi>;

using mp = M<int, int>;
using mset = MS<int>;
using pq = PQ<int>;
using rpq = RPQ<int>;
using dq = DQ<int>;

// }}}

// Vector Macros {{{

#define pb push_back
#define pf push_front

#define sz(x) int((x).size())

#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()

#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))

#define ft front()
#define bk back()

#define pb push_back
#define pf push_front

// }}}

// Other Macros {{{

#define f first
#define s second

#define rtn return
#define brk break

#define lb lower_bound
#define ub upper_bound

// }}}

// For Loops {{{

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto& x : a)

// }}}

// Constants {{{

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const db PI = acos((db)-1);

// For grid problems...
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dx2[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy2[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };

// }}}

// Utility Functions {{{

#define fastIO() cin.tie(0)->sync_with_stdio(0)

bool eq(db a, db b, db eps = 0.00001)
{
  return abs(a - b) < eps;
}

#define swap(a, b) \
{                \
  auto tmp = a;  \
  a = b;         \
  b = tmp;       \
}

#define init(a)         \
{                     \
  for (auto& x : a) { \
    x = 0;            \
  }                   \
}

#define init2d(a)         \
{                       \
  for (auto& y : a) {   \
    for (auto& x : y) { \
      x = 0;            \
    }                   \
  }                     \
}

pi EO(vi a)
{
  pi eo;
  for (auto& x : a) {
    if (x % 2) {
      eo.s++;
    } else {
      eo.f++;
    }
  }
  return eo;
}

// }}}

// Input {{{

#define tcTUU template <class T, class... U>

tcT void in(T& t)
{
  cin >> t;
}

tcTUU void in(T& t, U&... u)
{
  cin >> t;
  in(u...);
}

tcTU void in(P<T, U>& p)
{
  cin >> p.f >> p.s;
}

tcTS void in(A<T, SZ>& a)
{
  each(a, x) in(x);
}

tcT void in(V<T>& v)
{
  each(v, x) in(x);
}

tcT void in(V<T>& v, int n)
{
  rep(n) {
    T x;
    in(x);
    v.pb(x);
  }
}

tcTUU void in(V<T>& v, int n, U... m)
{
  rep(n) {
    T x;
    in(x, m...);
    v.pb(x);
  }
}

tcT void in(S<T>& s, int n)
{
  rep(n) {
    T x;
    in(x);
    s.insert(x);
  }
}

tcTUU void in(S<T>& s, int n, U... m)
{
  rep(n) {
    T x;
    in(x, m...);
    s.insert(x);
  }
}

tcT void in(M<T,int>& m, int n)
{
  rep(n) {
    T x;
    in(x);
    m[x]++;
  }
}

tcT void in(M<T,V<int>>& m, int n)
{
  F0R(i, n) {
    T x;
    in(x);
    m[x].pb(i);
  }
}

tcTU void in(PQU<T,U>& p, int n)
{
  rep(n) {
    T x;
    in(x);
    p.push(x);
  }
}

// }}}

// Output {{{

#define tcTT template<class ...T>

tcT void out_sep(str sep, T t)
{
  cout << t;
}

tcTUU void out_sep(str sep, T t, U... u)
{
  out_sep(sep, t), cout << sep, out_sep(sep, u...);
}

tcTT void out(T... t)
{
  out_sep(" ", t...), cout << '\n';
}

tcTT void out(T... t, str sep)
{
  out_sep(sep, t...), cout << '\n';
}

tcT void out(V<T> v)
{
  for (auto& x : v) {
    out(x);
  }
  cout << "\n";
}

tcTU void out(V<P<T, U>>& v)
{
  for (auto& x : v) {
    cout << x.f << " " << x.s << "\n";
  }
  cout << "\n";
}

tcTS void out(V<A<T, SZ>>& v)
{
  for (auto& y : v) {
    for (auto& x : y) {
      cout << x << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

tcT void out(V<V<T>>& v)
{
  for (auto& y : v) {
    for (auto& x : y) {
      cout << x << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

tcT void out(S<T>& s)
{
  for (auto& x : s) {
    cout << x << " ";
  }
  cout << "\n";
}

tcT void out(MS<T>& m)
{
  for (auto& x : m) {
    cout << x << " ";
  }
  cout << "\n";
}

tcT void out(PQ<T>& p)
{
  PQ<T> P = p;
  while (P.size()) {
    auto& x = P.top();
    P.pop();
    cout << x << " ";
  }
  cout << "\n";
}

tcT void out(RPQ<T>& p)
{
  RPQ<T> P = p;
  while (P.size()) {
    auto& x = P.top();
    P.pop();
    cout << x << " ";
  }
  cout << "\n";
}

tcT void out(DQ<T>& d)
{
  for (auto& x : d) {
    cout << x << " ";
  }
  cout << "\n";
}

tcTU void out(M<T, U>& m)
{
  for (auto& x : m) {
    out(x.f, x.s);
  }
  cout << "\n";
}

// }}}

// }}}

// ––– CODE –––

void solve(int T)
{
  int n;
  in(n);

  V<vi> a;
  in(a, n, n);

  out(a);
  out(a);
}

int32_t main()
{
  fastIO();

  bool TC = true;

  // Comment out if there are multiple test cases...
  TC = false;

  if (TC) {
    /* int T; in(T); */
    /* F0R(i, T) solve(i); */
  } else {
    solve(0);
  }
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON"T GET STUCK ON ONE APPROACH
 */
