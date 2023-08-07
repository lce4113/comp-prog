// USACO 2021 January Silver: Problem C

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define int long long

int32_t main() {
  int n;
  cin >> n;
  vector<vi> grid(n, vi(n, 0));
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      cin >> grid[i][k];
    }
  }

  int ans1 = 0;
  for (int i = 0; i < n; i++) {
    int even = 0, odd = 0;
    for (int k = 0; k < n; k++) {
      if (k % 2) {
        even += grid[i][k];
      } else {
        odd += grid[i][k];
      }
    }
    ans1 += max(even, odd);
  }

  int ans2 = 0;
  for (int i = 0; i < n; i++) {
    int even = 0, odd = 0;
    for (int k = 0; k < n; k++) {
      if (k % 2) {
        even += grid[k][i];
      } else {
        odd += grid[k][i];
      }
    }
    ans2 += max(even, odd);
  }

  cout << max(ans1, ans2) << '\n';
}
