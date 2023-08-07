// ––– USACO 2022 US Open Silver: Problem C –––

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
using vl = vector<ll>;
using pl = pair<ll, ll>;

void solve() {
  string a;
  int Q;
  cin >> a >> Q;

  vector<int> pfs_c(1, 0), pfs_o(1, 0), pfs_w(1, 0);
  for (auto x : a) {
    pfs_c.push_back(pfs_c.back() + (x == 'C'));
    pfs_o.push_back(pfs_o.back() + (x == 'O'));
    pfs_w.push_back(pfs_w.back() + (x == 'W'));
  }

  while (Q--) {
    pair<int, int> q;
    cin >> q.f >> q.s;
    int c = pfs_c[q.s] - pfs_c[q.f - 1];
    int o = pfs_o[q.s] - pfs_o[q.f - 1];
    int w = pfs_w[q.s] - pfs_w[q.f - 1];
    if ((c % 2 == 1 && o % 2 == 0 && w % 2 == 0) ||
        (c % 2 == 0 && o % 2 == 1 && w % 2 == 1)) {
      cout << "Y";
      continue;
    }
    cout << "N";
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
