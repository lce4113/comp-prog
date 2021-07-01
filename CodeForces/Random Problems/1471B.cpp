// ––– CodeForces Contest 1471, Problem B: "Strange List" –––

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

  ll t;
  cin >> t;
  while (t--) {
    ll n, x;
    cin >> n >> x;

    ll arr[n], ans = 0;
    for (ll i = 0; i < n; i++) {
      ll x;
      cin >> x;
      arr[i] = x;
      ans += x;
    }

    bool b = false;
    for (ll i = 1;; i++) {
      for (ll k = 0; k < n; k++) {
        if (arr[k] % x) {
          goto done;
        } else {
          arr[k] /= x;
          ans += pow(x, i) * arr[k];
        }
      }
    }

  done:
    cout << ans << '\n';
  }
}
