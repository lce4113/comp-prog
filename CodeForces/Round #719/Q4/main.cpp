// ––– CodeForces Round #719: Problem D –––

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
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    map<ll, ll> m;
    for (ll i = 0; i < n; i++) {
      ll elt;
      cin >> elt;
      ll e = elt - i;
      if (m[e])
        m[e]++;
      else
        m[e] = 1;
    }
    ll ans = 0;
    for (const auto& p : m) {
      ans += p.s * (p.s - 1) / 2;
    }
    cout << ans << endl;
  }
}
