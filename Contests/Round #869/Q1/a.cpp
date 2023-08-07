// CodeForces Round #869: Problem A

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void solve() {
  int n, k;
  cin >> n >> k;
  string a;
  cin >> a;
  int ans = 1;
  for (int i = 1; i < n; i++) {
    string b;
    cin >> b;
    if (a == b) ans++;
  }
  cout << ans << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
