// USACO 2023 US Open Bronze: Problem A

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  string a;
  cin >> n >> a;

  int min = 0, max = 0, inc = 2;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == 'B' && a[i + 1] == 'B') min++, max++;
    if (a[i] == 'E' && a[i + 1] == 'E') min++, max++;
  }

  for (int i = 0; i < n; i++) {
    if (a[i] == 'F') {
      char start = (i == 0 ? ' ' : a[i - 1]);
      int len = 0;
      while (a[i] == 'F') i++, len++;
      char end = (i == n ? ' ' : a[i]);
      /* cout << start << ' ' << end << '\n'; */
      if (start == ' ' && end == ' ') {
        inc = 1;
        max += len - 1;
      } else if (start == ' ' || end == ' ') {
        inc = 1;
        max += len;
      } else if (start == end) {
        min += 1 - (len % 2);
        max += len + 1;
      } else {
        min += len % 2;
        max += len;
      }
    }
  }

  vector<int> ans;
  for (int i = min; i <= max; i += inc) ans.push_back(i);
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << '\n';
}

int32_t main() {
  int t = 1;
  /* cin >> t; */
  while (t--) solve();
}
