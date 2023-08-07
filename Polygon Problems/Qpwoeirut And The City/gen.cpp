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
    vector<int> test;
    for (int i = 0; i < n; i++) {
      int h = rnd.next(MIN_H, MAX_H);
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
