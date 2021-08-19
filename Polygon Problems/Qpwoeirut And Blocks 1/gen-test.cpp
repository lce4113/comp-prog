// ––– "Qpwoeirut And Grid" - Test Generator –––

#include "testlib.h"
#include <iostream>

using ll = long long;

using namespace std;

ll tpow(int n)
{
  ll x = 1;
  for (int i = 0; i < n; i++) {
    x *= 10;
  }
  return x;
}

int main(int argc, char** argv)
{
  registerGen(argc, argv, 1);

  ll n1 = tpow(atoi(argv[1])), n2 = tpow(atoi(argv[2]));
  ll n = rnd.next(n1, n2);
  cout << n << '\n';
}
