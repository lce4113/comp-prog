// CodeForces Round #865: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  if (n % 2) {
    cout << "YES\n";
    return;
  }
  int curr = 0;
  for (auto x : a) curr = x - curr;
  if (curr >= 0) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
