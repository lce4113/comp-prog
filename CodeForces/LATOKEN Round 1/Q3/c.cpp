// ––– CodeForces LATOKEN Round 1: Problem C –––

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

const ll MOD = 1e9 + 7;

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;

    ll arr1[n + 1];
    for (ll i = 1; i <= n; i++) {
      ll x;
      cin >> x;
      arr1[i] = x;
    }

    ll arr2[n + 1];
    for (ll i = 1; i <= n; i++) {
      ll x;
      cin >> x;
      arr2[i] = x;
    }

    ll c[n + 1];
    for (ll i = 1; i <= n; i++) {
      c[arr1[i]] = arr2[i];
    }

    multiset<ll> m;
    for (int i = 1; i <= n; i++) {
      m.insert(i);
    }

    ll ans = 1;
    while (m.size()) {
      for (ll i = 0, a = *m.begin(), b = a; b != a || i == 0; b = c[b], i++) {
        m.erase(b);
      }
      ans *= 2;
      ans %= MOD;
    }

    cout << ans << '\n';
  }
}
