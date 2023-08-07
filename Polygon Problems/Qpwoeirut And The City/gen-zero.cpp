// ––– "Qpwoeirut and the City" - Test Generator –––

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

  int n1 = atoi(argv[1]), n2 = atoi(argv[2]);

  int nsum = 0;
  vector<vector<int>> tests;
  while (tests.size() < MAX_T) {
    int n = rnd.next(n1, n2);
    if (nsum + n > MAX_SUM_N) break;
    int skip = -1;
    if (n % 2 == 0) {
      int randpos = rnd.next(1, 4);
      if (randpos == 1) {
        // 0010101010...0101010
        skip = 1;
      } else if (randpos == 2 || randpos == 3) {
        // 0101...010010...1010
        skip = rnd.next(1, n) / 2 * 2 - 1;
      } else {
        // 010101010...01010100
        skip = n - 1;
      }
    }
    vector<int> test;
    test.push_back(rnd.next(MIN_H, MAX_H));
    bool less = true;
    for (int i = 1; i < n; i++) {
      int h;
      if (i != skip) less = !less;
      if (less) {
        h = rnd.next(MIN_H, test.back());
      } else {
        h = rnd.next(test.back(), MAX_H);
      }
      test.push_back(h);
    }
    tests.push_back(test);
    nsum += n;
  }

  cout << tests.size() << '\n';
  for (vector<int> test : tests) {
    cout << test.size() << '\n';
    for (int i = 0; i < test.size(); i++) {
      if (i != 0) cout << ' ';
      cout << test[i];
    }
    cout << '\n';
  }
}
