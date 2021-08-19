// ––– CodeForces Round #731: Problem C –––

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

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int k, n, m;
    cin >> k >> n >> m;

    int a[n];
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[i] = x;
    }

    int b[m];
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      b[i] = x;
    }

    vi c;
    for (int i = 0, k = 0; c.size() < n + m;) {
      if (k == m) {
        c.pb(a[i]);
        i++;
      } else if (i == n) {
        c.pb(b[k]);
        k++;
      } else if (a[i] < b[k]) {
        c.pb(a[i]);
        i++;
      } else {
        c.pb(b[k]);
        k++;
      }
    }

    for (auto& x : c) {
      if (x == 0) {
        k++;
      } else if (x > k) {
        goto done;
      }
    }

    for (auto& x : c) {
      cout << x << ' ';
    }
    cout << '\n';
    continue;
  done:
    cout << -1 << '\n';
  }
}
