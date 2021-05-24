// ––– USACO 2017 December Bronze: Problem C –––

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

pair<str, ll> changes[100];
map<str, ll> cows = {
  { "Bessie", 7 },
  { "Elsie", 7 },
  { "Mildred", 7 },
};

str wcow() {
  str ans = "";
  ll m = -1;
  for (auto c : cows) {
    if (c.s == m) ans += c.f;
    if (c.s > m) {
      m = c.s;
      ans = c.f;
    }
  }
  return ans;
}

int main()
{
  ifstream cin("measurement.in");
  ofstream cout("measurement.out");

  ll n;
  cin >> n;

  for (ll i = 0; i < 100; i++) {
    changes[i] = mp(">[", 0);
  }

  for (ll i = 0; i < n; i++) {
    ll day, change;
    str cow;
    char neg;
    cin >> day >> cow >> neg >> change;
    if (neg == '-') change *= -1;
    changes[day - 1] = mp(cow, change);
  }

  ll ans = 0;
  str w = "hEhE";
  for (ll i = 0; i < 100; i++) {
    pair<str, ll> c = changes[i];
    if (c.f != ">[") {
      cows[c.f] += c.s;
      str wc = wcow();
      if (w != wc) {
        ans++;
        w = wc;
      }
    }
  }

  cout << ans << '\n';
}
