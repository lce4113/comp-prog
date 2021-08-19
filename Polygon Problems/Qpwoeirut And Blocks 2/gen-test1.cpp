// ––– "Qpwoeirut And Grid" - Test Generator –––

#include "testlib.h"
#include <bits/stdc++.h>

using ll = long long;

using namespace std;

int main(int argc, char** argv)
{
  registerGen(argc, argv, 1);

  ll n = atoi(argv[1]);

  ll a = sqrt(n), mn, mx = 2 * n + 2;
  if (n == a * a) {
    mn = 4 * a;
  } else if (n <= a * (a + 1)) {
    mn = 4 * a + 2;
  } else {
    mn = 4 * a + 4;
  }

  ll t = mx - mn + 6;
  cout << t << '\n';
  while (t--) {
    ll x = mn + t - 3;
    cout << n << ' ' << x << '\n';
  }
}
