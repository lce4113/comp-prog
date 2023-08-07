// CodeForces Round #875: Problem C

#include <bits/stdc++.h>
using namespace std;

int maxTwo(vector<int> arr) {
  int maxx = 0, mask = 0, n = arr.size();

  set<int> s;

  for (int i = 9; i >= 0; i--) {

    // setting the i'th bit in mask
    mask |= (1 << i);

    for (int i = 0; i < n; ++i) {
      s.insert(arr[i] & mask);
    }

    int newMaxx = maxx | (1 << i);

    for (int prefix : s) {
      if (s.count(newMaxx ^ prefix)) {
        maxx = newMaxx;
        break;
      }
    }
    s.clear();
  }

  return maxx;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<int> b(1, 0);
  int curr = 0;
  for (auto x : a) {
    curr ^= x;
    b.push_back(curr);
  }
  int ans = maxTwo(b);
  cout << ans << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
