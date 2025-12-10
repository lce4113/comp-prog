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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;

void die() {
  cout << "-1\n";
  exit(0);
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<string> g(n);
  vector<vector<int>> poss(k);
  for(int i = 0; i < n; i++) {
    cin >> g[i];
    for(int j = 0; j < k; j++) {
      if(g[i][j] != 'X') poss[j].pb(i);
    }
  }
  vector<int> correct(n);
  string ret = "";
  auto dfs = y_combinator([&](auto self) -> bool {
    if(sz(ret) == k) return true;
    for(auto want: "FT") {
      if(!want) continue;
      bool can = true;
      for(auto out: poss[sz(ret)]) {
        if(g[out][sz(ret)] == want) {
          if(++correct[out] > 1) can = false; 
        }
      }
      ret += want;
      if(can && self()) return true;
      ret.pop_back();
      for(auto out: poss[sz(ret)]) correct[out] -= g[out][sz(ret)] == want;
    }
    return false;
  }); 
  if(!dfs()) ret = "-1";
  else assert(sz(ret) == k);
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}