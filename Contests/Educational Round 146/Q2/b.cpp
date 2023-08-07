// CodeForces Educational Round 146: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    int ms[6] = {1,
                 max(x, y),
                 (int)sqrt(max(x, y)),
                 (int)sqrt(x + y),
                 (int)ceil(sqrt(x + y)),
                 (int)sqrt(x + y) + 1};
    int ans = LLONG_MAX;
    for (auto m : ms) {
      int curr = ceil((double)x / m) + ceil((double)y / m) + m - 1;
      ans = min(ans, curr);
    }
    cout << ans << '\n';
  }
}
