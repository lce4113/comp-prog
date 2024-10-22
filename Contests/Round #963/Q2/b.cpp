// CodeForces Round #963: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  sort(a.begin(), a.end());
  int modd = 0, moddi = 0, odd = 0, even = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2) {
      if (a[i] > modd) modd = a[i], moddi = i;
      odd++;
    } else {
      even++;
    }
  }
  int mx = a[n - 1];
  if (odd == 0) {
    cout << 0 << '\n';
    return;
  }
  if (mx % 2 == 1) {
    cout << even << '\n';
    return;
  }
  int teven = a[moddi];
  for (int i = 0; i < n; i++) {
    if (a[i] > teven) break;
    if (a[i] % 2 == 0) teven += a[i];
  }
  int ans = even + 1;
  if (teven > mx) {
    ans = even;
  }
  cout << ans << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
