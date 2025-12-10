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

void solve() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> start(n, -1);
    vector<int> nextID(2*n-2);
    vector<int> to(2*n-2);
    for(int i = 0; i+1 < n; i++) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      to[2*i] = b;
      nextID[2*i] = start[a];
      start[a] = 2*i;
      to[2*i+1] = a;
      nextID[2*i+1] = start[b];
      start[b] = 2*i+1;
    }
    vector<int> dp(n);
    vector<int> q(n);
    auto bfs = [&](int src) -> int {
      fill(all(dp), 1e9);
      int ql = 0;
      int qr = 0;
      dp[src] = 0;
      q[qr++] = src;
      while(ql < qr) {
        src = q[ql++];
        for(int id = start[src]; id != -1; id = nextID[id]) {
          int out = to[id];
          if(updmin(dp[out], dp[src]+1)) q[qr++] = out;
        }
      }
      return src;
    };
    int x = bfs(bfs(0));
    vector<int> p(n);
    for(auto& xx: p) {
      cin >> xx;
      xx--;
    }
    if(dp[x] <= 3) {
      cout << "1\n";
      continue;
    }
    vector<int> dist(n);
    vector<int> currid(n, -1);
    vector<int> color(n);
    int ret = 1;
    for(int i = 0; ret && i + 1 < n; i++) {
      int ql = 0;
      int qr = 0;
      q[qr++] = p[i];
      q[qr++] = p[i+1];
      currid[p[i]] = i;
      currid[p[i+1]] = i;
      color[p[i]] = 0;
      color[p[i+1]] = 1;
      dist[p[i]] = 0;
      dist[p[i+1]] = 0;
      bool good = false;
      while(ql < qr && !good) {
        int curr = q[ql++];
        for(int id = start[curr]; !good && id != -1; id = nextID[id]) {
          int out = to[id];
          if(currid[out] == i && color[out] != color[curr]) {
            good = true;
            break;
          }
          if(currid[out] != i) {
            dist[out] = dist[curr] + 1;
            color[out] = color[curr];
            currid[out] = i;
            if(dist[out] == 1 && color[out] == 0) q[qr++] = out;
          }
        }
      }
      if(!good) ret = 0;
    }
    cout << ret << "\n";
  }
}

int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  solve();
}
