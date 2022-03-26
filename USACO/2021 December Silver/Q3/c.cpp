// ––– USACO 2021 December Silver: Problem C –––

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using db = double;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second

void solve();
int32_t main() { solve(); }

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      /* cout << a[i] + b[i] << ' ' << a[k] + b[k] << '\n'; */
      for (int l = a[i] + a[k]; l <= (b[i] + b[k]); l++) {
        mp[l]++;
      }
    }
  }

  for (int i = 0; i < 2 * m + 1; i++) {
    cout << (mp[i] ? mp[i] : 0) << '\n';
  }
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
