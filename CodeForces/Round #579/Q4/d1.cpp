// ––– CodeForces Round #579: Problem D1 –––

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

const int MAXN = 1e5 + 5;

str s, t;
int n, m;
int dp[MAXN][MAXN];

int e(int a, int b)
{
  int asdf = dp[a][b];
  if (asdf) {
    return asdf;
  }

  if (b == m) {
    return n - a;
  }
  int ans = -1;
  for (int i = a; i < n; i++) {
    str c = s.substr(i, 1), d = t.substr(b, 1);
    if (c == d) {
      int x = e(i + 1, b + 1);
      if (x != -1) {
        ans = max({ ans, i - a, x });
      }
    }
  }

  dp[a][b] = ans;
  return ans;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  cin >> s >> t;
  n = s.length(), m = t.length();

  int ans = e(0, 0);
  cout << ans << '\n';
}
