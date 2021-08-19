// ––– CodeForces Round #735: Problem E –––

// TEMPLATE {{{

#include <bits/stdc++.h>
using namespace std;

// Data Type Aliases {{{

#define tcT template <class T>
#define tcTU template <class T, class U>
#define tcTS template <class T, size_t SZ>
#define tcS template <size_t SZ>

tcT using V = vector<T>;
tcTS using A = array<T, SZ>;
tcS using AR = array<int, SZ>;
tcTU using P = pair<T, U>;
tcT using S = set<T>;
tcTU using M = map<T, U>;
tcT using MS = multiset<T>;
tcT using PQ = priority_queue<T>;
tcTU using PQU = priority_queue<T, V<T>, U>;
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

// Loops {{{

#define GET_FOR(_1,_2,_3,NAME,...) NAME
#define FOR(...) GET_MACRO(__VA_ARGS__, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define ROF(...) GET_MACRO(__VA_ARGS__, ROF3, ROF2, ROF1)(__VA_ARGS__)

#define FOR3(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR2(i, b) FOR3(i, 0, b)
#define FOR1(n) FOR2(_, n)

#define F0R(i, b) FOR2(i, b)
#define rep(n) FOR1(_, n)

#define ROF3(i, b, a) for (int i = (b)-1; i >= (a); --i)
#define ROF2(i, b) ROF3(i, b, 0)

#define R0F(i, b) ROF2(i, b)

#define each(a, x) for (auto &x : a)

// }}}

// Constants {{{

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const db PI = acos((db)-1);

// For grid problems...
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dx2[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy2[8] = {1, 1, 1, 0, -1, -1, -1, 0};

// }}}

// Utility Functions {{{

#define stdIO() cin.tie(0)->sync_with_stdio(0)
#define fileIO(f)                                                              \
{                                                                            \
  ifstream cin(f + ".in");                                                   \
  ofstream cout(f + ".out");                                                 \
}

bool eq(db a, db b, db eps = 0.00001) { return abs(a - b) < eps; }

#define swap(a, b)                                                             \
{                                                                            \
  auto tmp = a;                                                              \
  a = b;                                                                     \
  b = tmp;                                                                   \
}

#define init(a)                                                                \
{                                                                            \
  for (auto &x : a) {                                                        \
    x = 0;                                                                   \
  }                                                                          \
}

#define init2d(a)                                                              \
{                                                                            \
  for (auto &y : a) {                                                        \
    for (auto &x : y) {                                                      \
      x = 0;                                                                 \
    }                                                                        \
  }                                                                          \
}

pi EO(vi a) {
  pi eo;
  for (auto &x : a) {
    if (x % 2) {
      eo.s++;
    } else {
      eo.f++;
    }
  }
  return eo;
}

// }}}

// Helpers {{{

#define tcTV template<class T, class = void>

inline namespace Helpers {
  // ––– is_iterable –––
  // https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
  // this gets used only when we can call begin() and end() on that type
  tcTV struct is_iterable : false_type {};
  tcT struct is_iterable<T,
      void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>
        > : true_type {};
  tcT constexpr bool is_iterable_v = is_iterable<T>::value;

  // ––– is_readable –––
  tcTV struct is_readable : false_type {};
  tcT struct is_readable<T, typename std::enable_if_t<
    is_same_v<decltype(cin >> declval<T&>()), istream&>
    > > : true_type {};
  tcT constexpr bool is_readable_v = is_readable<T>::value;

  // ––– is_printable –––
  // https://nafe.es/posts/2020-02-29-is-printable/
  tcTV struct is_printable : false_type {};
  tcT struct is_printable<T, typename std::enable_if_t<
    is_same_v<decltype(cout << declval<T>()), ostream&>
    > > : true_type {};
  tcT constexpr bool is_printable_v = is_printable<T>::value;
}

// }}}

// Input {{{

#define tcTUU template <class T, class... U>

tcT void in(T &t) { cin >> t; }

tcTUU void in(T &t, U &...u) {
  cin >> t;
  in(u...);
}

tcTU void in(P<T, U> &p) { cin >> p.f >> p.s; }

tcTS void in(A<T, SZ> &a) { each(a, x) in(x); }

tcT void in(V<T> &v) { each(v, x) in(x); }

tcT void in(V<T> &v, int n) {
  rep(n) {
    T x;
    in(x);
    v.pb(x);
  }
}

tcTUU void in(V<T> &v, int n, U... m) {
  rep(n) {
    T x;
    in(x, m...);
    v.pb(x);
  }
}

tcT void in(S<T> &a, int n) {
  rep(n) {
    T x;
    in(x);
    a.insert(x);
  }
}

tcTUU void in(S<T> &a, int n, U... m) {
  rep(n) {
    T x;
    in(x, m...);
    a.insert(x);
  }
}

tcT void in(M<T, int> &m, int n) {
  rep(n) {
    T x;
    in(x);
    m[x]++;
  }
}

tcT void in(M<T, V<int>> &m, int n) {
  F0R(i, n) {
    T x;
    in(x);
    m[x].pb(i);
  }
}

tcTU void in(PQU<T, U> &p, int n) {
  rep(n) {
    T x;
    in(x);
    p.push(x);
  }
}

// }}}

// To String {{{

tcT typename enable_if<is_printable_v<T>,str>::type ts(T x) {
  stringstream ss; ss << fixed << setprecision(15) << x;
  return ss.str();
}

tcTU str ts(P<T, U> p) { return ts(p.f) + " " + ts(p.s); }

tcT typename enable_if<!is_iterable_v<T>, str>::type ts(V<T> v) {
  str res = "";
  each(v, x) res += ts(x) + " ";
  res += "\n";
  rtn res;
}

tcT typename enable_if<is_iterable_v<T>, str>::type ts(V<T> v) {
  str res = "";
  each(v, x) res += ts(x);
  res += "\n";
  rtn res;
}

tcTS typename enable_if<!is_iterable_v<T>, str>::type ts(A<T,SZ> a) {
  str res = "";
  each(a, x) res += ts(x) + " ";
  res += "\n";
  rtn res;
}

tcTS typename enable_if<is_iterable_v<T>, str>::type ts(A<T,SZ> a) {
  str res = "";
  each(a, x) res += ts(x);
  res += "\n";
  rtn res;
}

// }}}

// Output {{{

#define tcTT template <class... T>

tcT void out(T t) { cout << ts(t) << "\n"; }

tcT void out_sep(str sep, T t) { cout << ts(t); }

tcTUU void out_sep(str sep, T t, U... u) {
  out_sep(sep, t), cout << sep, out_sep(sep, u...);
}

tcTT void out(T... t) { out_sep(" ", t...), cout << "\n"; }

// }}}

// Main {{{

void solve(int T);
bool TC();

int32_t main() {
  stdIO();

  if (TC()) {
    int T; in(T);
    F0R(i, T) solve(i);
  } else {
    solve(0);
  }
}

// }}}

// }}}

// ––– CODE –––

bool TC() {
  return false; // Comment this line out for multiple test cases
  return true;
}

void solve(int T) {

}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON"T GET STUCK ON ONE APPROACH
 */
