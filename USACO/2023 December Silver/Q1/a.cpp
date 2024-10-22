// USACO 2023 December Silver: Problem A

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int>> towers(M, vector<int>(1, INT_MAX));
  int ans = 0;
  vector<pair<int, int>> wa(N);
  for (int i = 0; i < N; i++) {
    int w, a;
    cin >> w >> a;
    wa[i] = {w, a};
  }
  sort(wa.rbegin(), wa.rend());
  for (int i = 0; i < N; i++) {
    int w = wa[i].first, a = wa[i].second;
    for (int k = 0, num = 0; k < M && num < a; k++, num++) {
      if (w > towers[k].back() - K) continue;
      towers[k].push_back(w);
      ans++;
    }
    /* for (auto t : towers) { */
    /*   for (auto x : t) cout << x << ' '; */
    /*   cout << '\n'; */
    /* } */
    /* cout << '\n'; */
  }
  cout << ans << '\n';
}
