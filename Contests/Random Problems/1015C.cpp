// ––– CodeForces Songs Compression: Problem C –––

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

  ll n, m;
  cin >> n >> m;

  ll x = 0;
  vi y;
  for (int i = 0; i < n; i++) {
    int a;
    int b;
    cin >> a >> b;

    x += a;
    y.pb(a - b);
  }

  sort(y.rbegin(), y.rend());

  int i = 0;
  while (x > m) {
    if (i == y.size()) {
      cout << -1 << '\n';
      return 0;
    }
    x -= y[i];
    i++;
  }

  cout << i << '\n';
}
