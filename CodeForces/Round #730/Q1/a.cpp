// ––– CodeForces Round #730: Problem A –––

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
    ll a, b;
    cin >> a >> b;

    if (a == b) {
      cout << 0 << ' ' << 0 << '\n';
      continue;
    }

    if (a < b) {
      ll tmp = a;
      a = b;
      b = tmp;
    }

    ll x = a % (a - b);
    x = min(x, (a - b) - x);
    ll y = a - b;

    cout << y << ' ' << x << '\n';
  }
}
