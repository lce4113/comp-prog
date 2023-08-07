// USACO 2023 January Silver: Problem A

#include <bits/stdc++.h>
using namespace std;
using str = string;
#define int long long

void solve() {
  str a, b;
  cin >> a >> b;
  int n = a.length();
  map<char, char> c;
  map<char, int> in;
  set<char> d, f;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (c[a[i]] && c[a[i]] != b[i]) {
      cout << -1 << '\n';
      return;
    }
    d.insert(a[i]);
    f.insert(b[i]);
    if (c[a[i]]) continue;
    c[a[i]] = b[i];
    in[b[i]]++;
    if (a[i] != b[i]) ans++;
  }

  int sz = f.size();
  while (d.size()) {
    char x = *d.begin();
    char start = x;
    bool inc = true;
    d.erase(x);
    x = c[x];
    if (in[x] > 1) inc = false;
    if (start == x) continue;
    while (d.count(x) && c[x] && x != c[x]) {
      d.erase(x);
      x = c[x];
      if (in[x] > 1) inc = false;
    }
    if (start == x && inc) {
      if (sz == 52) {
        cout << -1 << '\n';
        return;
      }
      ans++;
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
