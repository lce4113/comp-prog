// ––– CodeForces Round #746: Problem C –––

// TEMPLATE {{{

#include <bits/stdc++.h>
using namespace std;

// Template Classes + Data Type Aliases {{{

#define tcT template <class T>
#define tcTT template <class... T>
#define tcTU template <class T, class U>
#define tcTUU template <class T, class... U>
#define tcTUV template <class T, class U, class V>
#define tcTUVV template <class T, class U, class... V>
#define tcS template <size_t S>
#define tcTS template <class T, size_t S>
#define tcTUS template <class T, class U, size_t S>
#define tcTSUU template <class T, size_t S, class... U>
#define tcTSUV template <class T, size_t S, class U, class V>
#define tcTSUVV template <class T, size_t S, class U, class... V>
#define tcTV template <class T, class = void>

tcT using V = vector<T>;
tcTS using A = array<T, S>;
tcS using AR = array<int, S>;
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

using st = S<int>;
using mp = M<int, int>;
using mvi = M<int, vi>;
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

#define rev reverse

#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))

#define ft front()
#define bk back()

#define pb push_back
#define pf push_front

#define ins insert

// }}}

// Other Macros {{{

#define f first
#define s second

#define rtn return
#define brk break

#define lb lower_bound
#define ub upper_bound

// }}}

// Mod Calculations {{{

const int MOD = 1e9 + 7;
tcT int mod(T n) { rtn(n % MOD); }

bool is_mod();
tcTU T add(T a, U b) { rtn is_mod() ? mod(a + b) : a + b; };
tcTU T mult(T a, U b) { rtn is_mod() ? mod(mod(a) * mod(b)) : (a * b); };

  // }}}

  // Loops {{{

#define FOR4(i, a, b, c) for (int i = (a); i < (b); i = add(i, c))
#define FOR3(i, a, b) FOR4(i, a, b, 1)
#define FOR2(i, b) FOR3(i, 0, b)
#define FOR1(n) FOR2(_, n)

#define ROF4(i, b, a, c) for (int i = (b)-1; i >= (a); i -= (c))
#define ROF3(i, b, a) ROF4(i, b, a, 1)
#define ROF2(i, b) ROF3(i, b, 0)
#define ROF1(n) ROF2(_, n)

#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME

#define FOR(...)                                 \
  GET_MACRO(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1) \
  (__VA_ARGS__)

#define ROF(...)                                 \
  GET_MACRO(__VA_ARGS__, ROF4, ROF3, ROF2, ROF1) \
  (__VA_ARGS__)

#define F0R(i, b) FOR2(i, b)
#define rep(n) FOR1(n)
#define R0F(i, b) ROF2(i, b)

#define each(a, x) for (auto &x : a)

// }}}

// Constants {{{

const ll INF = 1e18;
const db PI = acos((db)-1);

// For grid problems...
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dx2[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy2[8] = {1, 1, 1, 0, -1, -1, -1, 0};

// }}}

// Helpers {{{

inline namespace Helpers {
// ––– is_iterable –––
// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
// this gets used only when we can call begin() and end() on that type
tcTV struct is_iterable : false_type {};
tcT struct is_iterable<
    T, void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>>
    : true_type {};
tcT constexpr bool is_iterable_v = is_iterable<T>::value;

// ––– is_readable –––
tcTV struct is_readable : false_type {};
tcT struct is_readable<T, typename std::enable_if_t<is_same_v<
                              decltype(cin >> declval<T &>()), istream &>>>
    : true_type {};
tcT constexpr bool is_readable_v = is_readable<T>::value;

// ––– is_printable –––
// https://nafe.es/posts/2020-02-29-is-printable/
tcTV struct is_printable : false_type {};
tcT struct is_printable<T, typename std::enable_if_t<is_same_v<
                               decltype(cout << declval<T>()), ostream &>>>
    : true_type {};
tcT constexpr bool is_printable_v = is_printable<T>::value;
} // namespace Helpers

// }}}

// Input {{{

tcT void in(T &t);
tcTUU void in(T &t, U &...u);
tcTU void in(P<T, U> &p);
tcTS void in(A<T, S> &a);
tcT void in(V<T> &a);
tcT void in(V<T> &a, int n);
tcTUU void in(V<T> &a, int n, U... m);
tcT void in(S<T> &a, int n);
tcTUU void in(S<T> &a, int n, U... m);
tcTU void in(PQU<T, U> &a, int n);
tcT void in(M<T, int> &a, int n);
tcT void in(M<T, V<int>> &a, int n);
tcT void in(M<T, S<int>> &a, int n);
tcT void in(M<T, MS<int>> &a, int n);
tcTU void in(M<T, PQU<int, U>> &a, int n);

tcT void in(T &t) { cin >> t; }

tcTUU void in(T &t, U &...u) { in(t), in(u...); }

tcTU void in(P<T, U> &p) { in(p.f), in(p.s); }

tcTS void in(A<T, S> &a) { each(a, x) in(x); }

tcT void in(V<T> &a) { each(a, x) in(x); }

tcT void in(V<T> &a, int n) {
  rep(n) {
    T x;
    in(x);
    a.pb(x);
  }
}

tcTUU void in(V<T> &a, int n, U... m) {
  rep(n) {
    T x;
    in(x, m...);
    a.pb(x);
  }
}

tcT void in(S<T> &a, int n) {
  rep(n) {
    T x;
    in(x);
    a.ins(x);
  }
}

tcTUU void in(S<T> &a, int n, U... m) {
  rep(n) {
    T x;
    in(x, m...);
    a.ins(x);
  }
}

tcTU void in(PQU<T, U> &a, int n) {
  rep(n) {
    T x;
    in(x);
    a.push(x);
  }
}

tcT void in(M<T, int> &a, int n) {
  rep(n) {
    T x;
    in(x);
    a[x] = add(a[x], 1);
  }
}

tcT void in(M<T, V<int>> &a, int n) {
  F0R(i, n) {
    T x;
    in(x);
    a[x].pb(i);
  }
}

tcT void in(M<T, S<int>> &a, int n) {
  F0R(i, n) {
    T x;
    in(x);
    a[x].ins(i);
  }
}

tcT void in(M<T, MS<int>> &a, int n) {
  F0R(i, n) {
    T x;
    in(x);
    a[x].ins(i);
  }
}

tcTU void in(M<T, PQU<int, U>> &a, int n) {
  F0R(i, n) {
    T x;
    in(x);
    a[x].push(i);
  }
}

// }}}

// To String {{{

tcT typename enable_if<is_printable_v<T>, str>::type ts(T x);
tcTU str ts(P<T, U> p);
tcT str ts(V<T> v);
tcTS str ts(A<T, S> a);
tcT str ts(S<T> a);
tcT str ts(MS<T> a);
tcT str ts(DQ<T> a);
tcTU str ts(M<T, U> a);
tcTU str ts(PQU<T, U> a);

tcT typename enable_if<is_printable_v<T>, str>::type ts(T x) {
  stringstream ss;
  ss << fixed << setprecision(15) << x << " ";
  rtn ss.str();
}

tcTU str ts(P<T, U> p) { rtn ts(p.f) + ts(p.s) + "\n"; }

tcT str ts(V<T> v) {
  str res = "";
  each(v, x) res += ts(x);
  res += "\n";
  rtn res;
}

tcTS str ts(A<T, S> a) {
  str res = "";
  each(a, x) res += ts(x);
  res += "\n";
  rtn res;
}

tcT str ts(S<T> a) {
  str res = "";
  each(a, x) res += ts(x);
  res += "\n";
  rtn res;
}

tcT str ts(MS<T> a) {
  str res = "";
  each(a, x) res += ts(x);
  res += "\n";
  rtn res;
}

tcT str ts(DQ<T> a) {
  str res = "";
  each(a, x) res += ts(x);
  res += "\n";
  rtn res;
}

tcTU str ts(M<T, U> a) {
  str res = "";
  each(a, x) res += ts(x);
  res += "\n";
  rtn res;
}

tcTU str ts(PQU<T, U> a) {
  str res = "";
  PQU<T, U> b = a;
  while (sz(b)) {
    res += ts(b.top());
    b.pop();
  }
  res += "\n";
  rtn res;
}

// }}}

// Output {{{

tcT void out(T t) { cout << ts(t) << "\n"; }

tcT void out_sep(str sep, T t) { cout << ts(t); }

tcTUU void out_sep(str sep, T t, U... u) {
  out_sep(sep, t), cout << sep, out_sep(sep, u...);
}

tcTT void out(T... t) { out_sep("", t...), cout << "\n"; }

// }}}

// Math Functions {{{

tcT struct C {
  T n;
  vl fact, inv;

  C(T _n) : n(_n) {
    fact.assign(n, 1), inv.assign(n, 1);
    FOR(i, 1, n) {
      fact[i] = mod(fact[i - 1] * (ll)i);
      inv[i] = binexp(fact[i], MOD - 2);
    }
  }

  ll binexp(ll a, ll b) {
    if (b == 0) rtn 1ll;
    if (b == 1) rtn mod(a);
    if (b % 2) rtn mod(a * binexp(a, b - 1));
    rtn binexp(mod(a * a), b / 2);
  }

  ll choose(ll a, ll b) {
    if (a < b) rtn 0;
    ll res = mod(fact[a] * inv[b]);
    res *= inv[a - b], res %= MOD;
    rtn res;
  }
};

// factorial function
tcT ll fact(T n) {
  ll res = 1;
  FOR(i, 2, add(n, 1)) res = mult(res, i);
  rtn res;
}

// exponent function
tcT T exp(T a, T b) {
  T res = 1;
  FOR(b) res = mult(res, a);
  rtn res;
}

// prime factorize an integer
tcT M<T, T> pfac(T a) {
  M<T, T> ans;
  T n = a;
  for (int i = 2; mult(i, i) <= a; i = add(i, 1)) {
    while (n % i == 0) {
      n /= i;
      ans[i] = add(ans[i], 1);
    }
  }
  if (n > 1) ans[n] = add(ans[n], 1);
  rtn ans;
}

// }}}

// Other Functions {{{

// search through a sorted vector with binary search
tcT int se(V<T> a, T b) {
  if (b < a[0]) rtn 0;
  int m, l = 0, r = sz(a);
  while (r - l > 1) {
    m = (l + r) / 2;
    if (b == a[m])
      rtn m;
    else if (b > a[m])
      l = m;
    else
      r = m;
  }
  rtn r;
}

// get the lower bound of se
tcT int lse(V<T> a, T b) {
  int c = se(a, b);
  c--;
  while (a[c] == b && c >= 0) c--;
  rtn(c + 1);
}

// get the upper bound of se
tcT int use(V<T> a, T b) {
  int c = se(a, b);
  c++;
  while (a[c] == b && c < sz(a)) c++;
  rtn(c - 1);
}

// add indices to a vector/array
tcT V<P<T, int>> addind(V<T> a) {
  V<P<T, int>> b;
  FOR(i, sz(a)) b.pb({a[i], i});
  rtn b;
}
tcTS A<P<T, int>, S> addind(A<T, S> a) {
  A<P<T, int>, S> b;
  FOR(i, sz(a)) b[i] = {a[i], i};
  rtn b;
}

// get the digits of a number (in reverse)
tcT vi dg(T n) {
  vi a;
  while (n) {
    a.pb(n % 10);
    n /= 10;
  }
  rtn a;
}

// fill a vector/array with a value
tcTUS void fill(A<T, S> &a, U b = 0);
tcTU void fill(V<T> &a, U b = 0);
tcTU void fill(T &a, U b = 0) { a = b; }
tcTUS void fill(A<T, S> &a, U b) { each(a, x) fill(x, b); }
tcTU void fill(V<T> &a, U b) { each(a, x) fill(x, b); }

// std io / file io
#define stdIO() cin.tie(0)->sync_with_stdio(0)
#define fileIO(f)              \
  {                            \
    ifstream cin(f + ".in");   \
    ofstream cout(f + ".out"); \
  }

// check for equality between doubles
tcT bool eq(T a, T b, T eps = 0.00001) { rtn abs(a - b) < eps; }

// swap two variables
#define swap(a, b) \
  {                \
    auto tmp = a;  \
    a = b;         \
    b = tmp;       \
  }

// get the number of even and odd numbers in a vector/array
tcT pi EO(V<T> a) {
  int E = 0, O = 0;
  each(a, x) {
    if (x % 2)
      O = add(O, 1);
    else
      E = add(E, 1);
  }
  rtn{E, O};
}

tcTS pi EO(A<T, S> a) {
  int E = 0, O = 0;
  each(a, x) {
    if (x % 2)
      O = add(O, 1);
    else
      E = add(E, 1);
  }
  rtn{E, O};
}

// Copy {{{

tcT T copy(T a);
tcTS A<T, S> copy(A<T, S> a);
tcT V<T> copy(V<T> a);
tcT S<T> copy(S<T> a);
tcT MS<T> copy(MS<T> a);
tcTU M<T, U> copy(M<T, U> a);
tcTU PQU<T, U> copy(PQU<T, U> a);

tcT T copy(T a) { rtn a; }

tcTS A<T, S> copy(A<T, S> a) {
  A<T, S> b;
  FOR(i, S) b[i] = copy(a[i]);
  rtn b;
}

tcT V<T> copy(V<T> a) {
  vi b;
  each(a, x) b.pb(copy(x));
  rtn b;
}

tcT S<T> copy(S<T> a) {
  S<T> b;
  each(a, x) b.ins(copy(x));
  rtn b;
}

tcT MS<T> copy(MS<T> a) {
  MS<T> b;
  each(a, x) b.ins(copy(x));
  rtn b;
}

tcTU M<T, U> copy(M<T, U> a) {
  M<T, U> b;
  each(a, x) b[copy(x.f)] = copy(x.s);
  rtn b;
}

tcTU PQU<T, U> copy(PQU<T, U> a) {
  PQU<T, U> b;
  while (sz(a)) {
    b.push(copy(a.top()));
    a.pop();
  }
  rtn b;
}

// }}}

// Sum {{{

// get the sum of values (plain integers, vectors, arrays, etc.)

tcT T sum(V<T> a, bool m = false) {
  T res = 0;
  each(a, x) {
    res = add(res, x);
    if (m) res %= MOD;
  }
  rtn res;
}

tcTS T sum(A<T, S> a, bool m = false) {
  T res = 0;
  each(a, x) {
    res = add(res, x);
    if (m) res %= MOD;
  }
  rtn res;
}

tcT T sum(S<T> a, bool m = false) {
  T res = 0;
  each(a, x) {
    res = add(res, x);
    if (m) res %= MOD;
  }
  rtn res;
}

tcT T sum(MS<T> a, bool m = false) {
  T res = 0;
  each(a, x) {
    res = add(res, x);
    if (m) res %= MOD;
  }
  rtn res;
}

tcTU U sum(M<T, U> a, bool m = false) {
  U res = 0;
  each(a, x) {
    res = add(res, x.s);
    if (m) res %= MOD;
  }
  rtn res;
}

tcTU T sum(PQU<T, U> a, bool m = false) {
  auto b = copy(a);
  T res = 0;
  while (sz(b)) {
    res = add(res, b.top()), b.pop();
    if (m) res %= MOD;
  }
  rtn res;
}

tcT T sum(T a) { rtn a; }
tcTUU T sum(T a, U... b) { rtn add(sum(a), sum(b...)); }
tcTUVV T sum(P<T, U> a, V... b) { rtn add(sum(a), sum(b...)); }
tcTUU T sum(V<T> a, U... b) { rtn add(sum(a), sum(b...)); }
tcTSUU T sum(A<T, S> a, U... b) { rtn add(sum(a), sum(b...)); }
tcTUU T sum(S<T> a, U... b) { rtn add(sum(a), sum(b...)); }
tcTUU T sum(MS<T> a, U... b) { rtn add(sum(a), sum(b...)); }
tcTUVV T sum(PQU<T, U> a, V... b) { rtn add(sum(a), sum(b...)); }
tcTUVV T sum(M<T, U> a, V... b) { rtn add(sum(a), sum(b...)); }

// }}}

// Min/Max {{{

tcT vi amaxi(T a) {
  vi mi{0};
  FOR(i, 1, sz(a)) {
    if (a[i] > a[mi[0]])
      mi.clear(), mi.pb(i);
    else if (a[i] == a[mi[0]])
      mi.pb(i);
  }
  rtn mi;
}

tcT vi amini(T a) {
  vi mi{0};
  FOR(i, 1, sz(a)) {
    if (a[i] < a[mi[0]])
      mi.clear(), mi.pb(i);
    else if (a[i] == a[mi[0]])
      mi.pb(i);
  }
  rtn mi;
}

tcT int maxi(T a) { rtn amaxi(a)[0]; }
tcT int mini(T a) { rtn amini(a)[0]; }

tcT T max(V<T> a) { rtn a[maxi(a)]; }
tcT T max(S<T> a) { rtn *a.rbegin(); }
tcT T max(MS<T> a) { rtn *a.rbegin(); }

tcT T min(V<T> a) { rtn a[mini(a)]; }
tcT T min(S<T> a) { rtn *a.begin(); }
tcT T min(MS<T> a) { rtn *a.begin(); }

tcTUU T min(T a, U... b) { rtn min(a, min(b...)); }
tcTUU T max(T a, U... b) { rtn min(a, min(b...)); }

// }}}

// Seg Tree {{{

tcT struct Seg {
  using F = T (*)(T, T);

  F comb = sum;
  int n;
  T ID = 0;
  V<T> seg;

  Seg(V<T> a) { init(a); }
  Seg(V<T> a, T _ID) : ID(_ID) { init(a); }
  Seg(V<T> a, F _comb) : comb(_comb) { init(a); }
  Seg(V<T> a, F _comb, T ID) : comb(_comb), ID(ID) { init(a); }

  void init(V<T> a) {
    n = pow(2, ceil(log2(sz(a))));
    seg.assign(n, 0);
    each(a, x) seg.pb(x);
    FOR(n - sz(a)) seg.pb(0);
    ROF(i, n, 1) calc(i);
  }

  void calc(int i) { seg[i] = comb(seg[2 * i], seg[add(2 * i, 1)]); }

  void u(int i, T val) {
    assert(i >= 0), assert(i < n);
    i = add(i, n), seg[i] = val;
    for (i /= 2; i; i /= 2) calc(i);
  }

  T q(int L) { rtn q(L, add(L, 1)); }
  T q(int L, int R) { rtn q(L, R, 0, n, 1); }
  T q(int L, int R, int l, int r, int i) {
    assert(L >= 0), assert(L < n);
    assert(R > 0), assert(R <= n);
    if (l >= R || r <= L) rtn ID;
    if (l >= L && r <= R) rtn seg[i];
    T ans = ID;
    ans = comb(ans, q(L, R, l, add(l, r) / 2, 2 * i));
    ans = comb(ans, q(L, R, add(l, r) / 2, r, add(2 * i, 1)));
    rtn ans;
  }
};

// }}}

// }}}

// Main {{{

void solve(int32_t T);
bool TC();

int32_t main() {
  stdIO();

  if (TC()) {
    int T;
    in(T);
    F0R(i, T)
    solve(i);
  } else {
    solve(0);
  }
}

// }}}

// }}}

// ––– CODE –––

// Uncomment for integer overflow
/* #define int ll */

bool TC() {
  /* rtn true; // Uncomment this line for multiple test cases */
  rtn false;
}

bool is_mod() {
  /* rtn true; // Uncomment this line for problems mod 1e9+7 */
  rtn false;
}

void solve(int32_t T) { out(pfac(40)); }

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
