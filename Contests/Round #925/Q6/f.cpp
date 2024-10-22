// CodeForces Round #925: Problem F

#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
map<int,int> dp;

int fact(int n) {
  if (dp[n]) return dp[n];
  if (n == 0) return 1;
  int ans = fact(n-1);
  ans *= n;
  ans %= MOD;
  dp[n]=ans;
  return ans;
}

int comb() {

}

void solve() {
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
