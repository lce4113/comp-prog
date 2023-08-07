// USACO 2023 US Open Silver: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
using str = string;
using vi = vector<int>;
#define pb push_back

int32_t main() {
  str a;
  cin >> a;
  int n = a.size();

  vi e(n), ie(n), sie(n), ssie(n), essie(n), bessie(n + 1, 0);
  int curr = n;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 'e') curr = i;
    e[i] = curr;
  }
  curr = n;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 'i') curr = e[i];
    ie[i] = curr;
  }
  curr = n;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 's') curr = ie[i];
    sie[i] = curr;
  }
  curr = n;
  int prev = n;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 's') curr = prev, prev = sie[i];
    ssie[i] = curr;
  }
  curr = n;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 'e') curr = ssie[i];
    essie[i] = curr;
  }

  /* for (auto x : essie) cout << x << ' '; */
  /* cout << '\n'; */

  curr = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 'b') {
      bessie[i] = bessie[essie[i]] + (n - essie[i]);
    } else {
      bessie[i] = bessie[i + 1];
    }
  }
  /* for (auto x : bessie) cout << x << ' '; */
  /* cout << '\n'; */

  int ans = 0;
  for (auto x : bessie) ans += x;
  cout << ans << '\n';
}
