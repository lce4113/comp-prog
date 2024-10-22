// CodeForces Round #938: Problem B

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, c, d;
  cin >> n >> c >> d;
  map<int, int> nums;
  int mn = INT_MAX;
  for (int i = 0; i < n * n; i++) {
    int x;
    cin >> x;
    nums[x]++;
    mn = min(mn, x);
  }
  map<int, int> numsr;
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      numsr[mn + i * c + k * d]++;
    }
  }
  for (auto x : nums) {
    if (numsr[x.first] != x.second) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  return;
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
