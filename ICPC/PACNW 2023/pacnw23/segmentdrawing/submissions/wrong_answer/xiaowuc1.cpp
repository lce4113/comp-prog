#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
typedef vector<int> vi;
#define f first
#define s second
#define derr if(1) cerr

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define debug(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << flush;
// END NO SAD

template<class Fun>
class y_combinator_result {
  Fun fun_;
public:
  template<class T>
  explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

  template<class ...Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template<class T>
bool updmin(T& a, T b) {
  if(b < a) {
    a = b;
    return true;
  }
  return false;
}
template<class T>
bool updmax(T& a, T b) {
  if(b > a) {
    a = b;
    return true;
  }
  return false;
}
typedef int64_t ll;

mt19937 g1(0x14004);
int get_random_int(int a, int b) {
  return uniform_int_distribution<int>(a, b)(g1);
}
void die() {
  cout << "-1\n";
  exit(0);
}
void solve() {
  auto srct = clock();
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  vector<double> lhs(n), rhs(n);
  for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> lhs[i] >> rhs[i];
  set<int> seen;
  while(clock() - srct < 1.9 * CLOCKS_PER_SEC) {
    int a = get_random_int(0, n-1);
    if(seen.count(a)) continue;
    seen.insert(a);
    for(int i = 0; i < a; i++) {
      if(y[i] < y[a]) continue;
      if(y[i] == y[a] && x[i] > x[a]) die();
      if(y[i] == y[a]) continue;
      double xcand;
      if(x[a] == x[i]) xcand = x[i];
      else {
        double slope = (y[a] - y[i]) / double(x[a] - x[i]);
        xcand = x[i] - y[i]/slope;
      }
      updmin(rhs[i], xcand);
    }
    for(int i = a+1; i < n; i++) {
      if(y[i] < y[a]) continue;
      if(y[i] == y[a] && x[i] < x[a]) die();
      if(y[i] == y[a]) continue;
      double xcand;
      if(x[a] == x[i]) xcand = x[i];
      else {
        double slope = (y[a] - y[i]) / double(x[a] - x[i]);
        xcand = x[i] - y[i]/slope;
      }
      updmax(lhs[i], xcand);
    }
  }
  for(int i = 0; i < n; i++) if(lhs[i] > rhs[i]) die();
  double ret = 0;
  for(int i = 0; i < n; i++) {
    if(lhs[i] <= x[i] && x[i] <= rhs[i]) ret += y[i];
    else {
      double mind = min(fabs(lhs[i] - x[i]), fabs(rhs[i] - x[i]));
      ret += sqrt(mind*mind+y[i]*ll(y[i]));
    }
  }
  cout << fixed << setprecision(39) << ret << "\n";
}

// what would chika do
// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points
// are you not using modint when you should

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
