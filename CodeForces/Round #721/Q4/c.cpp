// ––– CodeForces Round #721: Problem C –––

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

ll choose3(int n)
{
  return (n) * (n - 1) * (n - 2) / 6;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    map<ll, vi> arr;
    for (ll i = 0; i < n; i++) {
      ll elt;
      cin >> elt;
      arr[elt].pb(i);
    }

    ll ans = 0;
    for (pair<int, vi> num : arr) {
      ll tot = 0;
      for (ll i : num.second) {
        ans += (n - i) * tot;
        tot += (i + 1);
      }
    }

    cout << ans << '\n';
  }
}
