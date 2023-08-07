// ––– USACO 2022 December Silver: Problem C –––

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int n;
  cin >> n;
  vector<int> one, two;
  for (int i = n; i > 0; i--) {
    for (int k = 0; k < i; k++) {
      int x;
      cin >> x;
      if (k == 1) one.push_back(x);
      if (k == 2) two.push_back(x);
    }
  }

  vector<int> dir(1, 1);
  for (int i = 0; i < n - 2; i++) {
    int x = i, y = i + 1;
    while (one[x] == 0 || x > 0) x--;
    if (two[i] == one[x] + one[y])
      dir.push_back(dir.back());
    else
      dir.push_back(dir.back() * (-1));
  }

  int curr = 0;
  cout << curr;
  for (int i = 0; i < n - 1; i++) {
    curr += one[i] * dir[i];
    cout << ' ' << curr;
  }
  cout << '\n';
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
