// ––– "Qpwoeirut and Towers" - Test Generator (Worst) –––

#include "testlib.h"
#include <iostream>

using namespace std;

#define MAXT 10'000
#define MAXN 200'000
#define MAXH 1'000'000'000

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);

  int t = 1;
  cout << t << '\n';
  while (t--) {
    int n = MAXN - (strcmp(argv[1], "odd") == 0);
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
      int h = (i % 3 ? 1 : MAXH);
      cout << h;
      if (i != n - 1) cout << ' ';
    }
    cout << '\n';
  }
}
