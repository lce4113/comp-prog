// ––– "Grid Split" - Test Generator (Worst) –––

#include "testlib.h"
#include <iostream>
/* #include <bits/stdc++.h> */

using namespace std;

#define MAXT 10'000
#define MAXN 200'000
#define MAXH 1'000'000'000

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);

  int t = 1;
  cout << t << '\n';
  while (t--) {
    int n = MAXN;
    cout << n << '\n';
    for (int x = 0; x < 2; x++) {
      for (int i = 0; i < n; i++) {
        int h = MAXH;
        if (i != 0) cout << " ";
        cout << h;
      }
      cout << '\n';
    }
  }
}
