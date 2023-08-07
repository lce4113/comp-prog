// USACO 2020 January Silver: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long

bool test(int x, int n, int k, int m) {
  int left = n, i = 0;
  while (left >= m * (x + 1)) {
    i++;
    left -= max(left / x, m);
  }
  i += ceil((double)left / m);
  return i <= k;
}

int valid(int x, int n, int k, int m) {
  int g = 0;
  while (k > 0 && g < n) {
    int y = (n - g) / x;
    if (y < m) {
      int leftover = (n - g + m - 1) / m;
      return leftover <= k;
    }
    int maxmatch = n - x * y;
    int numdays = (maxmatch - g) / y + 1;
    /* if (numdays > k) numdays = k; */
    g += y * numdays;
    k -= numdays;
  }
  return g >= n;
}

int32_t main() {
  ifstream cin("loan.in");
  ofstream cout("loan.out");

  int n, k, m;
  cin >> n >> k >> m;
  int l = 1;
  for (int r = floor(n / m) + 1; r - l > 1;) {
    int mid = (l + r) / 2;
    /* if (test(mid)) { */
    if (valid(mid, n, k, m)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << '\n';
}
