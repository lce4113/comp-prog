// ––– CodeForces Round #723: Problem B –––

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

const int MAXN = 1e9;

map<int, int> dp;

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    dp[0] = 1;
    for (int i = 0; i <= n - 11; i++) {
      int x = 11;
      if (dp[i] == 0)
        continue;
      for (int k = 100; i + x <= n; k *= 10) {
        dp[i + x] += dp[i];
        x += k;
      }
    }

    if (dp[n] > 0) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}
