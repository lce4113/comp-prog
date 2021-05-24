// ––– CSES Apartments –––

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

  ll n, m, k;
  cin >> n >> m >> k;

  ll a[n];
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll b[n];
  for (ll i = 0; i < m; i++) {
    cin >> b[i];
  }

  sort(a, a + n);
  sort(b, b + m);

  ll ans = 0;
  for (ll i = 0, l = 0; i < n && l < m;) {
    if (b[l] < a[i] - k)
      l++;
    else if (b[l] > a[i] + k)
      i++;
    else
      ans++, i++, l++;
  }
  cout << ans << '\n';
}
