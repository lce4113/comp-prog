// ––– CodeForces Round #579: Problem D2 –––

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
using str = string;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  str s, t;
  cin >> s >> t;

  int n = s.length(), m = t.length();
  int rg[m];
  for (int i = n - 1, k = m - 1; i >= 0; i--) {
    if (s[i] == t[k]) {
      rg[k] = i;
      k--;
    }
  }

  int ans = 0;
  for (int i = 0, k = 0; i < n; i++) {
    if (k == m) {
      ans = max(ans, n - i);
    } else {
      ans = max(ans, rg[k] - i);
    }
    if (k < m && s[i] == t[k]) {
      k++;
    }
  }

  cout << ans << '\n';
}
