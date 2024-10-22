// CodeForces Round #965: Problem C

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  for (auto &x : A) cin >> x;
  for (auto &x : B) cin >> x;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) a[i] = {A[i], B[i]};
  sort(a.begin(), a.end());
  int ans = a[n/2-1];
  for (int i = n - 1; i >= 0; i--) {
    if (a[i].second) {
      int sac = a[n - 1] - a[i];
      ans += k - sac;
      break;
    }
  }
  int diff = 0, i = n / 2 - 1, sum = 0;
  while (diff < k && i < n - 1) {
    sum += a[i];
    diff = k * a[i + 1] - sum;
    i++;
  }
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
