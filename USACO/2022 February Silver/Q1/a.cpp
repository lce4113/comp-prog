#include <bits/stdc++.h>
using namespace std;

#define pb push_back

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> a;
  for (int i = 0; i < n; i++) {
    a.pb({});
    for (int k = 0; k < n; k++) {
      int x;
      cin >> x;
      a[i].pb(x - 1);
    }
  }

  vector<vector<int>> b(n), m(n);
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      if (a[i][k] == i) break;
      b[i].pb(a[i][k]);
      m[a[i][k]].pb(i);
    }
  }
  a = b;

  set<int> erased1, erased2;
  bool B = true;
  while (B) {
    B = false;
    for (int i = 0; i < n; i++) {
      if (erased1.count(i)) continue;
      erased1.insert(i);
      if (a[i].size() == 0) {
        B = true;
        m[i] = {};
        vector<vector<int>> b(n);
        for (int k = 0; k < n; k++) {
          for (int l = 0; l < a[k].size(); l++) {
            if (a[k][l] == i) continue;
            b[k].pb(a[k][l]);
          }
        }
        a = b;
      }
    }

    for (int i = 0; i < n; i++) {
      if (erased2.count(i)) continue;
      erased2.insert(i);
      if (m[i].size() == 0) {
        B = true;
        a[i] = {};
        vector<vector<int>> p(n);
        for (int k = 0; k < n; k++) {
          for (int l = 0; l < m[k].size(); l++) {
            if (m[k][l] == i) continue;
            p[k].pb(a[k][l]);
          }
        }
        m = p;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (a[i].size() == 0) {
      cout << (i + 1) << '\n';
    } else {
      cout << (a[i][0] + 1) << '\n';
    }
  }
}

int32_t main() { solve(); }

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
