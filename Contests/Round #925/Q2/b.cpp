// CodeForces Round #925: Problem B

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  int sum = 0;
  for (auto x : a) sum += x;
  if (sum % n > 0) {
    cout << "NO" << '\n';
    return;
  }
  int avg = sum / n;

  for (auto &x : a) x -= avg;
  int curr = 0;
  for (auto x : a) {
    curr += x;
    if (curr < 0) {
      cout << "NO" << '\n';
      return;
    }
  }

  cout << "YES" << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
