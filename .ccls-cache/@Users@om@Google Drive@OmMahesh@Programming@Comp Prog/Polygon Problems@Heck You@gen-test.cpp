// ––– "Heck you." - Test Generator –––

#include "testlib.h"
#include <iostream>

using namespace std;

int tpow(int n)
{
  int ans = 1;
  for (int i = 0; i < n; i++) {
    ans *= 10;
  }
  return ans;
}

int main(int argc, char** argv)
{
  registerGen(argc, argv, 1);

  int n1 = tpow(atoi(argv[1])), n2 = tpow(atoi(argv[2]));
  int t1 = tpow(atoi(argv[3])), t2 = tpow(atoi(argv[4]));
  int c1 = tpow(atoi(argv[5])), c2 = tpow(atoi(argv[6]));
  int r1 = tpow(atoi(argv[7])), r2 = tpow(atoi(argv[8]));

  int n = rnd.next(n1, n2);
  int t = rnd.next(t1, t2);
  cout << n << ' ' << t << endl;
  for (int i = 1; i <= n; i++) {
    int ci = rnd.next(c1, c2);
    cout << ci;
    if (i != n) cout << ' ';
  }
  cout << endl;
  for (int i = 1; i <= t; i++) {
    int a = rnd.next(1, n);
    int b = rnd.next(1, n);
    int r = rnd.next(r1, r2);
    if (a > b) {
      int tmp = a;
      a = b;
      b = tmp;
    }
    cout << a << ' ' << b << ' ' << r << endl;
  }
}
