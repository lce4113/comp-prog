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

const int MAXN = 805;
short dp[MAXN][MAXN][MAXN];
void solve() {
  int n;
  cin >> n;
  vector<int> v; v.reserve(n+2);
  v.pb(0);
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    v.pb(x);
  }
  v.pb(0);
  int solo = 0;
  int numc = sz(v);
  while(true) {
    v.erase(unique(all(v)), v.end());
    vector<int> c;
    for(int out: v) c.pb(out);
    sort(all(c));
    c.erase(unique(all(c)), c.end());
    for(auto& x: v) x = lb(all(c), x) - c.begin();
    vector<int> f(sz(c));
    for(int out: v) f[out]++;
    bool done = true;
    for(int i = 0; i < sz(v); i++) {
      if(f[v[i]] == 1) {
        if(v[i]) solo++;
        v.erase(v.begin() + i--);
        done = false;
      }
    }
    if(!done) continue;
    numc = sz(c);
    break;
  }
  if(sz(v) == 0) {
    cout << solo << "\n";
    return;
  }
  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < sz(v); i++) {
    for(int a = 0; a < numc; a++) dp[1][i][a] = 1;
    dp[1][i][v[i]] = 0;
  }
  for(int len = 2; len <= sz(v); len++) {
    memset(dp[len], 3, sizeof(dp[len]));
    for(int innerlen = 1; innerlen < len; innerlen++) {
      for(int i = 0; i + len <= sz(v); i++) {
        for(int a = 0; a < numc; a++) {
          updmin(dp[len][i][v[i]],
            short(dp[innerlen][i][v[i]] + dp[len-innerlen][i+innerlen][a] + (v[i] != a))
          );
        }
      }
    }
  }
  cout << solo + dp[sz(v)][0][0] << "\n";
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
