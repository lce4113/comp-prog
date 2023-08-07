// USACO 2021 January Silver: Problem A

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define pb push_back

int32_t main() {
  int n, k;
  cin >> n >> k;

  vi cows(n);
  vector<set<int>> hits(n);
  for (int i = 0; i < n; i++) {
    cows[i] = i;
    hits[i].insert(i);
  }
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    int tmp = cows[a];
    cows[a] = cows[b];
    cows[b] = tmp;
    hits[cows[b]].insert(a);
    hits[cows[a]].insert(b);
    /* cout << cows[a] << ' ' << cows[b] << '\n'; */
  }
  /* for (int i = 0; i < n; i++) { */
  /*   cout << i << ": "; */
  /*   for (auto x : hits[i]) cout << x << ' '; */
  /*   cout << '\n'; */
  /* } */

  set<int> visited;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) visited.insert(i);
  while (visited.size()) {
    set<int> cycle;
    int start = *visited.begin();
    visited.erase(start);
    cycle.insert(start);
    int curr = cows[start];
    visited.erase(curr);
    cycle.insert(curr);
    while (curr != start) {
      curr = cows[curr];
      visited.erase(curr);
      cycle.insert(curr);
    }
    set<int> tot_hits;
    for (auto x : cycle) {
      /* cout << x << " : "; */
      for (auto h : hits[x]) {
        tot_hits.insert(h);
        /* cout << h << ' '; */
      }
      /* cout << ", "; */
    }
    /* cout << '\n'; */
    /* for (auto x : tot_hits) cout << x << ' '; */
    /* cout << '\n'; */
    for (auto x : cycle) ans[x] = tot_hits.size();
  }

  for (auto x : ans) cout << x << '\n';
}
