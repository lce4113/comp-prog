// USACO 2020 January Silver: Problem A

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define pb push_back
#define f first
#define s second

int32_t main() {
  ifstream cin("berries.in");
  ofstream cout("berries.out");

  int n, k;
  cin >> n >> k;
  k /= 2;
  vi trees(n);
  for (auto &t : trees) cin >> t;
  sort(trees.begin(), trees.end());

  int ans = -1;
  for (int div = 1; div <= trees.back(); div++) {
    int divs = 0;
    vi baskets;
    for (auto t : trees) {
      divs += t / div;
      baskets.pb(t % div);
    }
    sort(baskets.rbegin(), baskets.rend());
    if (divs < k) continue;
    divs -= k;
    if (divs >= k) {
      int tot = div * k;
      /* cout << tot << ' ' << div << "\n"; */
      ans = max(ans, tot);
    } else {
      int tot = divs * div;
      for (int i = 0; i < k - divs && i < baskets.size(); i++) {
        tot += baskets[i];
      }
      /* for (auto b : baskets) cout << b << ' '; */
      /* cout << ": "; */
      /* cout << tot << ' ' << div << "\n"; */
      ans = max(ans, tot);
    }
  }

  cout << ans << '\n';
}
