// ––– USACO 2022 January Silver: Problem B –––

#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
using ll = long long;
#define f first
#define s second

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int r = i + 1, mx = 0;
    while (r < n && mx < a[i]) {
      /* cout << a[i] << ' ' << a[r] << ' ' << mx << '\n'; */
      if (a[r] > mx) {
        mx = a[r];
        ans += r - i + 1;
      }
      r++;
    }
  }
  cout << ans << '\n';
}

int32_t main() { solve(); }

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
