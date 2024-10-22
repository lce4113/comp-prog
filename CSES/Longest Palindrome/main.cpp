// ––– CSES Longest Palindrome –––

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  string s2, s = "$";
  cin >> s2;
  for (auto x : s2) s += x, s += '$';
  int n = s.size();

  int l = 0, r = 0;
  vector<int> dp(n, -1);
  for (int i = 0; i < n; i++) {
    dp[i] = min(r - i, dp[l + (r - i)]);
    while (i - dp[i] >= 0 && i + dp[i] < n && s[i - dp[i]] == s[i + dp[i]])
      dp[i]++;
    if (i + dp[i] > r) l = i - dp[i], r = i + dp[i];
  }

  /* cout << s << '\n'; */
  /* for (auto x : dp) cout << x << ' '; */
  /* cout << '\n'; */
  int mi, mx = -1;
  for (int i = 0; i < n; i++) {
    if (dp[i] > mx) mi = i, mx = dp[i];
  }
  mx--;
  for (int i = mi - mx + 1; i <= mi + mx; i += 2) cout << s[i];
  cout << '\n';
}
