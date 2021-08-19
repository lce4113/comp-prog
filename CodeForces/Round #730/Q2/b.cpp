// ––– CodeForces Round #730: Problem B –––

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
    ll n;
    cin >> n;

    ll arr[n], sm = 0;
    for (ll i = 0; i < n; i++) {
      ll x;
      cin >> x;
      arr[i] = x;
      sm += x;
    }

    cout << (sm % n) * (n - (sm % n)) << '\n';
  }
}
