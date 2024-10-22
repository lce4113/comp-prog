// CodeForces Round #938: Problem E

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  string S;
  cin >> n >> S;
  for (int len = n; len >= 1; len--) {
    string s = S;
    /* if (len != 2) continue; */
    vector<int> a;
    for (int i = 0; i < n; i++) {
      auto start = lower_bound(a.begin(), a.end(), i - len + 1);
      auto end = upper_bound(a.begin(), a.end(), i);
      /* cout << i << ' ' << end - start << '\n'; */
      int inv = (end - start) % 2;
      int curr = (s[i] == '1') ^ inv;
      if (curr) s[i] = '1';
      if (!curr) {
        s[i] = '0';
        if (i + len - 1 < n) a.push_back(i), s[i] = '1';
      }
    }
    /* for (auto x : s) cout << x << ' '; */
    /* cout << '\n'; */
    /* for (auto x : a) cout << x << ' '; */
    /* cout << '\n'; */
    bool ones = true, zeroes = true;
    for (int i = n - len; i < n; i++) {
      if (s[i] == '1') zeroes = false;
      if (s[i] == '0') ones = false;
    }
    if (ones || zeroes) {
      cout << len << '\n';
      return;
    }
  }
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
