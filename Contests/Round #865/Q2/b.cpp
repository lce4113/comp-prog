// CodeForces Round #865: Problem B

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n, 0));
  for (int i = 0, k = 2 * n; i < n; i += 2, k -= 2) a[0][i] = k;
  for (int i = 1, k = 2; i < n; i += 2, k += 2) a[0][i] = k;
  for (int i = 0, k = n - 1; i < n; i += 2, k -= 2) a[1][i] = k;
  for (int i = 1, k = n + 1; i < n; i += 2, k += 2) a[1][i] = k;

  for (auto x : a) {
    for (auto y : x) {
      cout << y << ' ';
    }
    cout << '\n';
  }
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
