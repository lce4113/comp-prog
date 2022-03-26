// ––– CodeForces Contest 1091, Problem B: "New Year and the Treasure Geolocation" –––

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

  ll sx = 0, sy = 0;

  pair<ll, ll> arr[n];
  for (ll i = 0; i < n; i++) {
    ll x;
    ll y;
    cin >> x >> y;
    arr[i] = {x, y};
    sx += x;
    sy += y;
  }

  pair<ll, ll> arr2[n];
  for (ll i = 0; i < n; i++) {
    ll x;
    ll y;
    cin >> x >> y;
    arr2[i] = {x, y};
    sx += x;
    sy += y;
  }

  cout << (sx / n) << ' ' << (sy / n) << '\n';
}
