// CodeForces Round #925: Problem C

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  set<int> b;
  for (auto &x : a) {
    cin >> x;
    b.insert(x);
  }

  if (b.size() == 1) {
    cout << 0 << '\n';
    return;
  }

  int left = 1;
  for (int i = 1, start = a[0]; a[i] == start; i++) left++;
  int right = 1;
  for (int i = n - 2, start = a[n - 1]; a[i] == start; i--) right++;
  if (a[0] == a[n - 1]) {
    int ans = n - left - right;
    cout << ans << '\n';
    return;
  }
  int ans = min(n - left, n - right);
  cout << ans << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
