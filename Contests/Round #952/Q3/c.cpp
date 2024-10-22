// CodeForces Round #952: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  set<int> b;
  int sm = 0, ans = 0;
  for (auto x : a) {
    b.insert(x);
    sm += x;
    if (sm % 2 == 1) continue;
    if (b.count(sm / 2)) ans++;
  }
  cout << ans << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
