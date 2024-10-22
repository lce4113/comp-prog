// CodeForces Round #925: Problem E

#include <bits/stdc++.h>
using namespace std;

/* int rev(int n) { */
/*   vector<int> d; */
/*   while (n > 0) { */
/*     d.push_back(n % 10); */
/*     n /= 10; */
/*   } */
/*   int ans = 0; */
/*   for (int i = d.size() - 1, k = 1; i >= 0; i--, k *= 10) { */
/*     ans += k * d[i]; */
/*   } */
/*   return ans; */
/* } */

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<pair<int, int>> b;
  for (auto &x : a) {
    cin >> x;
    int mod = 10, i = 0;
    while (x % mod == 0) i++, mod *= 10;
    b.push_back({i, to_string(x).size()});
  }
  sort(b.rbegin(), b.rend());
  int len = 0;
  /* cout << '\n'; */
  for (int i = 0; i < n; i++) {
    /* cout << b[i].first << ' ' << b[i].second << '\n'; */
    if (i % 2 == 0) b[i].second -= b[i].first;
    len += b[i].second;
  }
  /* cout << len << '\n'; */
  if (len >= m + 1) {
    cout << "Sasha" << '\n';
    return;
  }
  cout << "Anna" << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
