// ––– USACO 2022 December Silver: Problem B –––

#include <bits/stdc++.h>
using namespace std;

set<int> modone, modthree;
#define MAXN 5'000'001

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    int x, y = 0;
    cin >> x;
    if (x % 4 == 1) {
      int lb = *(--modone.upper_bound(x));
      a.push_back({(x - lb) / 4, 0});
    } else if (x % 4 == 3) {
      int lb = *(--modthree.upper_bound(x));
      a.push_back({(x - lb) / 4, 0});
    } else if (x % 4 == 2) {
      a.push_back({x / 4, 0});
    } else {
      a.push_back({x / 4, 1});
    }
  }

  int m = a[0].first;
  for (auto x : a) {
    /* cout << x.first << '\n'; */
    m = min(m, x.first);
  }
  for (auto x : a) {
    if (x.first == m) {
      cout << (x.second ? "Farmer Nhoj" : "Farmer John") << '\n';
      break;
    }
  }
}

int32_t main() {
  bool prime[MAXN + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= MAXN; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= MAXN; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= MAXN; p++) {
    if (prime[p]) {
      if (p % 4 == 1) modone.insert(p);
      if (p % 4 == 3) modthree.insert(p);
    }
  }

  int t;
  cin >> t;
  while (t--) solve();
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
