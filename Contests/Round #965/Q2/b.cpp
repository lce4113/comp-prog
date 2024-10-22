// CodeForces Round #965: Problem B

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  map<int, int> mp;
  for (int i = 0; i < n; i++) mp[a[i]] = i;
  sort(a.begin(), a.end());
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    b[mp[a[(i + 1) % n]]] = a[i];
  }
  for (auto x : b) cout << x << ' ';
  cout << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
