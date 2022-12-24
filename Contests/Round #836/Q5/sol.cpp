#define _USE_MATH_DEFINES
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

#pragma warning(disable : 4996)
#define pb push_back
#define en '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define szof(x) int((x).size())
#define vec vector
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const int INF = 1000000000 + 1e8;
const ll LINF = 2000000000000000000;

int n, m, h;
vec<vec<pii>> g;

const ll mod = 1e9 + 7;

ll binpow(ll x, ll n) {
  ll p = 1;
  while (n) {
    if (n & 1) {
      p = (p * x) % mod;
    }
    n /= 2;
    x = (x * x) % mod;
  }
  return p;
}

vec<int> ans;
int ok = 1;
int cntComps = 0;

void dfs(int v, int x = 0) {
  ans[v] = x;

  for (auto [to, w] : g[v]) {
    if (ans[to] == -1) {
      dfs(to, (x + w) % h);
    } else {
      if (ans[to] != (x + w) % h) {
        ok = 0;
      }
    }
  }
}

void solve() {
  cin >> n >> m >> h;
  vec<vec<int>> a(n, vec<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  g.clear();
  g.resize(n);
  ans.clear();
  ans.resize(n, -1);
  ok = 1;
  cntComps = 0;

  int cntEmpty = 0;

  for (int j = 0; j < m; j++) {
    int last = -1;
    bool allEmpty = 1;
    for (int i = 0; i < n; i++) {
      if (a[i][j] != -1) {
        allEmpty = false;
        if (last != -1) {
          g[last].pb({i, (a[i][j] - a[last][j] + h) % h});
          g[i].pb({last, (a[last][j] - a[i][j] + h) % h});
        }
        last = i;
      }
    }
    cntEmpty += allEmpty;
  }

  for (int i = 0; i < n; i++) {
    if (ans[i] == -1) {
      dfs(i);
      cntComps++;
    }
  }

  cout << ok * binpow(h, cntEmpty + cntComps - 1) << en;
}

int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
#endif

  int tst = 1;
  cin >> tst;

  while (tst--) {
    solve();
  }
}
