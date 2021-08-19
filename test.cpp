// ––– HEADER –––

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
using str = string;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

int main() {
  int n;
  cin >> n;

  int arr[2][n], sm = 0;
  for (int i = 0; i < 2; i++) {
    for (int k = 0; k < n; k++) {
      int x;
      cin >> x;
      arr[i][k] = x;
      sm += x;
    }
  }
  sm /= 2;

  int pfs[2][n + 1];
  for (int i = 0; i < 2; i++) {
    pfs[i][0] = 0;
    for (int k = 1; k <= n; k++) {
      pfs[i][k] = pfs[i][k - 1] + arr[i][k - 1];
    }
  }

  int ans = 0;
  /* vector<pi> anspos; */
  for (int i = 0, k = n; i <= n && k >= 0;) {
    int psm = pfs[0][i] + pfs[1][k];
    if (psm == sm) {
      /* anspos.pb({i, k}); */
      ans++, i++, k--;
    } else if (psm < sm) {
      i++;
    } else {
      k--;
    }
  }

  cout << ans << '\n';
  /* for (auto& x : anspos) { */
  /*   cout << x.f << ' ' << x.s << '\n'; */
  /* } */
}
