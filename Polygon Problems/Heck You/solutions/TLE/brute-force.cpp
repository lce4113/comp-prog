// ––– "Heck you." - Brute Force Solution File –––

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

const int MAXN = 1e5;
const int MOD = 1e9 + 7;

int c[MAXN];
int n, t, a, b, r;

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> t;

  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  while (t--) {
    cin >> a >> b >> r;

    ll ans = 0;
    for (ll i = 1, k = a; k <= b; i += r, k++) {
      ans += c[k - 1] * i;
    }

    cout << ans % MOD << '\n';
  }
}
