// USACO 2023 US Open Silver: Problem B

#include <bits/stdc++.h>
using namespace std;

using str = string;

int n, c;
int diff(str a, str b) {
  int ans = 0;
  for (int i = 0; i < c; i++) {
    if (a[i] != b[i]) ans++;
  }
  return ans;
}

int32_t main() {
  cin >> c >> n;
  vector<string> x;
  for (int i = 0; i < n; i++) {
    str y;
    cin >> y;
    x.push_back(y);
  }
  for (int i = 0; i < n; i++) {
    int ans = -1;
    for (int k = 0; k < n; k++) {
      if (i == k) continue;
      ans = max(ans, diff(x[i], x[k]));
    }
    cout << ans << '\n';
  }
}
