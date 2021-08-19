// ––– "Qpwoeirut And Grid" - Test Generator –––

#include "testlib.h"
#include <iostream>

using namespace std;

int tpow(int n)
{
  int x = 1;
  for (int i = 0; i < n; i++) {
    x *= 10;
  }
  return x;
}

int main(int argc, char** argv)
{
  registerGen(argc, argv, 1);

  int t1 = tpow(atoi(argv[1])), t2 = tpow(atoi(argv[2]));
  int n1 = tpow(atoi(argv[3])), n2 = tpow(atoi(argv[4]));
  int a1 = tpow(atoi(argv[5])), a2 = tpow(atoi(argv[6]));

  int t = rnd.next(t1, t2);
  cout << t << '\n';
  while (t--) {
    int n = rnd.next(n1, n2);
    cout << n << '\n';

    long long sm = 0;
    for (int i = 1; i <= 2; i++) {
      for (int k = 1; k <= n; k++) {
        int ai = rnd.next(a1, a2);
        sm += ai;
        if (i == 2 && k == n && sm % 2 == 1) {
          ai = (ai == a2 ? ai - 1 : ai + 1);
        }
        cout << ai;
        if (k != n)
          cout << ' ';
      }
      cout << '\n';
    }
  }
}
