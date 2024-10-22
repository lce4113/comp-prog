// USACO 2023 December Silver: Problem B

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int N, K;
  cin >> N >> K;

  set<int> leftovers;
  for (int i = 1; i <= N; i++) leftovers.insert(i);

  map<int, int> pos;
  for (int i = 0; i < K; i++) {
    int x;
    cin >> x;
    leftovers.erase(x);
    pos[x] = i;
  }

  vector<int> b(N);
  for (auto &x : b) {
    cin >> x;
    leftovers.erase(x);
  }

  map<int, int> diffs1;
  for (int i = 0; i < K; i++) {
    int x = b[i];
    if (!pos.count(x)) continue;
    int diff = (pos[x] - i + K) % K;
    diffs1[diff]++;
  }

  map<int, int> diffs2;
  for (int i = 0; i < K; i++) {
    int x = b[i];
    if (!pos.count(x)) continue;
    int diff = ((K - 1 - pos[x]) - i + K) % K;
    diffs2[diff]++;
  }

  int ans = 0;
  for (auto x : diffs1) {
    /* cout << x.first << ' ' << x.second << '\n'; */
    ans = max(ans, x.second);
  }
  for (auto x : diffs2) {
    /* cout << x.first << ' ' << x.second << '\n'; */
    ans = max(ans, x.second);
  }
  ans += leftovers.size();
  cout << ans << '\n';
}
