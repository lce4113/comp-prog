// ––– "Qpwoeirut And Grid" - Fastest TLE Solution –––

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<ll> pfs_a, pfs_b;
    pfs_a.push_back(0), pfs_b.push_back(0);
    ll half_sum = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      pfs_a.push_back(pfs_a[i] + x);
      half_sum += x;
    }
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      pfs_b.push_back(pfs_b[i] + x);
      half_sum += x;
    }
    half_sum /= 2;

    set<ll> matches;
    for (int i = 0; i <= n; i++) {
      matches.insert(half_sum - pfs_a[i]);
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
      ans += matches.count(pfs_b[i]);
    }

    cout << ans << '\n';
  }
}
