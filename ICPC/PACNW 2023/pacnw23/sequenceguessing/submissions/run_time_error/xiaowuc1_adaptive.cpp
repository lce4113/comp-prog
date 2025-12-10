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

struct segtree {
  vector<int> rt;
  int SZ;
  segtree(int n) {
    SZ = 1;
    while(SZ < n) SZ *= 2;
    rt.resize(2*SZ);
  }
  void upd(int idx, int val) {
    idx += SZ;
    rt[idx] = val;
    while(idx > 1) {
      idx /= 2;
      rt[idx] = rt[2*idx] + rt[2*idx+1];
    }
  }
  int qry(int lhs, int rhs) {
    lhs += SZ;
    rhs += SZ;
    int ret = 0;
    while(lhs <= rhs) {
      if(lhs%2) ret += rt[lhs++];
      if(rhs%2==0) ret += rt[rhs--];
      lhs /= 2;
      rhs /= 2;
    }
    return ret;
  }
};

map<int, int> dp;
void solve() {
  dp[0] = 1;
  dp[100000] = 66668;
  auto qry = [&](int valtoprint) -> int {
    cout << valtoprint << endl;
    int ret;
    cin >> ret;
    return ret;
  };
  segtree avail(100001);
  for(int i = 1; i <= 99999; i++) avail.upd(i, 1);
  int curr = qry(66668);
  set<int> canp;
  set<int> forced; forced.insert(0); forced.insert(100000);
  set<int> forcedloc; forcedloc.insert(1); forcedloc.insert(66668);
  for(int i = 1; i <= 99999; i++) canp.insert(i);
  auto forceval = [&](int val, int loc) -> void {
    if(dp.count(val)) {
      assert(dp[val] == loc);
      return;
    }
    assert(!forcedloc.count(loc));
    forced.insert(val);
    forcedloc.insert(loc);
    dp[val] = loc;
  };
  while(curr >= 0) {
    canp.erase(curr);
    if(dp.count(curr)) {
      curr = qry(dp[curr]);
      continue;
    }
    else {
      dp[curr] = -1;
      avail.upd(curr, 0);
      auto it = forced.ub(curr);
      int above = *it; it--;
      int below = *it;
      // [below, above]
      if(dp.count(curr-1)) {
        forceval(curr+1, dp[curr-1]+1);
        continue;
      }
      if(dp.count(curr+1)) {
        forceval(curr-1, dp[curr+1]-1);
        continue;
      }
      // neither curr-1 nor curr+1 are correct
      int lhs = dp[below]+1;
      int rhs = dp[above]-1;
      assert(lhs < rhs);
      int lhsamt = avail.qry(below, curr);
      int rhsamt = avail.qry(curr, above);
      auto eval = [&](int lv, int rv) -> double {
        return fabs(lv/double(lhsamt) - rv/double(rhsamt));
      };
      int a = 1;
      int b = rhs-lhs;
      while(a+2 < b) {
        int c = (a+b)/2;
        int d = c+1;
        if(eval(c, rhs-lhs+1-c) < eval(d, rhs-lhs+1-d)) b = d;
        else a = c; 
      } 
      int use = -1;
      double error = 1e9;
      for(int x = a; x <= b; x++) {
        if(updmin(error, eval(x, rhs-lhs+1-x))) use = x;
      }
      forceval(curr-1, lhs+use-1);
      forceval(curr+1, lhs+use);
      curr = qry(dp[curr]);
    }
  }
  int amt = 0;
  for(int i = 0; i <= 100000; i++) {
    bool print = false;
    if(dp.count(i) && dp[i] >= 0) print = true;
    else if(!dp.count(i)) print = true;
    if(print) {
      amt++;
      cout << i << endl;
    }
  }
  assert(amt == 66668);
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
