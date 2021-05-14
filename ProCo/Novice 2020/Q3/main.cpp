// ––– ProCo Advanced 2020: Problem C –––

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

pl mcube(ll c)
{
  pl p = mp(-1, -1);
  for (ll x = 2, cube = 8; cube <= c; x++) {
    cube = x * x * x;
    if (c % cube != 0)
      continue;
    p = mp(x, c / cube);
  }
  return p;
}

int main()
{
  int t;
  cin >> t;
  while (t--) {
    ll c;
    cin >> c;

    pl mc = mcube(c);
    if (mc.f != -1) {
      cout << mc.f * mc.s << ' ' << mc.s << endl;
      continue;
    }

    cout << c * 4 << ' ' << c * 8 << endl;
  }
}
