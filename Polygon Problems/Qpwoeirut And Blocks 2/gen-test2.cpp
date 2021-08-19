// ––– "Qpwoeirut And Grid" - Test Generator –––

#include "testlib.h"
#include <bits/stdc++.h>

using ll = long long;

using namespace std;

ll tpow(ll n)
{
  ll x = 1;
  for (ll i = 0; i < n; i++) {
    x *= 10;
  }
  return x;
}

int main(int argc, char** argv)
{
  registerGen(argc, argv, 1);

  ll t1 = atoi(argv[1]), t2 = atoi(argv[2]);
  ll n1 = atoi(argv[3]), n2 = atoi(argv[4]);
  ll x1 = atoi(argv[5]), x2 = atoi(argv[6]);

  ll t = rnd.next(tpow(t1), tpow(t2));
  cout << t << '\n';
  while (t--) {
    ll n = rnd.next(tpow(n1), tpow(n2));
    ll x = rnd.next(tpow(x1), tpow(x2));
    cout << n << ' ' << x << '\n';
  }
}
