// ––– CodeForces LATOKEN Round 1: Problem B –––

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

    ll arr[n], ans = 0;
    for (ll i = 0; i < n; i++) {
      ll x;
      cin >> x;
      arr[i] = x;
      if (i != 0) {
        ans += abs(arr[i] - arr[i - 1]);
      }
    }
    ans += arr[0];
    ans += arr[n - 1];

    if (n == 1) {
      ans -= arr[0];
      goto done;
    }

    for (ll i = 0; i < n; i++) {
      if (i == 0) {
        if (arr[i] == max({arr[i], arr[i + 1]})) {
          ans -= arr[i] - arr[i + 1];
          arr[i] = arr[i + 1];
        }
      } else if (i == n - 1) {
        if (arr[i] == max({arr[i], arr[i - 1]})) {
          ans -= arr[i] - arr[i - 1];
          arr[i] = arr[i - 1];
        }
      } if (arr[i] == max({arr[i], arr[i - 1], arr[i + 1]})) {
        ans -= arr[i] - max(arr[i - 1], arr[i + 1]);
        arr[i] = max(arr[i - 1], arr[i + 1]);
      }
    }

done:
    cout << ans << '\n';
  }
}
