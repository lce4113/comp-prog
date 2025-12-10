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

bool valid(const vector<int>& s, int lhs, int rhs) {
  if(lhs < 0 || rhs >= sz(s)) return false;
  assert(rhs-lhs == 2);
  if(s[lhs] == s[lhs+1] || s[lhs] == s[rhs] || s[lhs+1] == s[rhs]) return false;
  return true;
}
vector<int> locs[3];
int dp[3][300005];
void solve() {
  vector<int> v;
  {
    string s;
    cin >> s;
    for(int i = 0; i < sz(s); i++) {
      v.pb(s[i]-'A');
      locs[v.back()].pb(i);
    }
  }
  for(int i = 0; i < sz(v); i++) {
    for(int a = 0; a < 3; a++) dp[a][i+1] = dp[a][i];
    dp[v[i]][i+1]++;
  }
  int ret = 1;
  for(int val = 0; val < 3; val++) {
    for(int i = 0; i <= sz(locs[val]); i++) {
      int lhs = 0;
      int rhs = sz(v);
      if(i-1 >= 0) lhs = locs[val][i-1];
      if(i < sz(locs[val])) rhs = locs[val][i];
      int cand = 0;
      for(int oval = 0; oval < 3; oval++) {
        if(val == oval) continue;
        updmax(cand, dp[oval][rhs] - dp[oval][lhs]);
      }
      if(valid(v, lhs, lhs+2)) cand--;
      if(valid(v, rhs-2, rhs)) cand--;
      updmax(ret, cand);
    }
  }
  cout << ret << "\n";
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
