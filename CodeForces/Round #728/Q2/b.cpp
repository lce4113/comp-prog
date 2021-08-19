// ––– CodeForces Round #728: Problem B –––

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
    ll n;
    cin >> n;

    ll arr[n + 1];
    for (ll i = 1; i <= n; i++) {
      ll x;
      cin >> x;
      arr[i] = x;
    }

    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
      ll a = arr[i];
      ll k = (-i);
      while (k <= i) {
        k += a;
      }
      for (; k <= n; k += a) {
        ll b = arr[k];
        if (a * b == i + k) {
          ans++;
        }
      }
    }

    cout << ans << "\n";
  }
}
