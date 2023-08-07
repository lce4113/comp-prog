// USACO 2019 December Silver: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  string f = "moobuzz";
  ifstream cin(f + ".in");
  ofstream cout(f + ".out");

  int n;
  cin >> n;
  n--;
  int resid[8] = {1, 2, 4, 7, 8, 11, 13, 14};
  int ans = n / 8 * 15 + resid[n % 8];
  cout << ans << '\n';
}
