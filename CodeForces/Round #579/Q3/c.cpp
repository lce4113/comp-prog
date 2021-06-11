// ––– CodeForces Round #579: Problem C –––

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

  ll n;
  cin >> n;

  ll g = 0;
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    g = gcd(g, x);
  }

  ll ans = 0;
  for (ll i = 1; i * i <= g; i++) {
    if (i * i == g) {
      ans++;
    } else if (g % i == 0) {
      ans += 2;
    }
  }

  cout << ans << '\n';
}
