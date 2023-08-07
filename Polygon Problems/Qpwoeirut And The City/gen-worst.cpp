// ––– "Qpwoeirut and the City" - Test Generator (Worst) –––

#include "testlib.h"
#include <iostream>
using namespace std;

#define MAX_T 10'000
#define MIN_N 3
#define MAX_N 100'000
#define MAX_SUM_N 200'000
#define MIN_H 1
#define MAX_H 1'000'000'000

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);

  int t = 2;
  cout << t << '\n';
  while (t--) {
    int n = MAX_N - t;
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
      int h = (i % 3 ? MIN_H : MAX_H);
      cout << h;
      if (i != n - 1) cout << ' ';
    }
    cout << '\n';
  }
}
