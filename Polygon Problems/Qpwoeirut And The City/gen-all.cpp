// ––– "Qpwoeirut and the City" - Test Generator (All Cases) –––

#include "testlib.h"
#include <iostream>
/* #include <bits/stdc++.h> */

using namespace std;

#define MAX_T 10'000
#define MIN_N 3
#define MAX_N 100'000
#define MAX_SUM_N 200'000
#define MIN_H 1
#define MAX_H 1'000'000'000

int t = 0, nsum = 0;
vector<vector<int>> tests;

void rand(int l, int r) {
  while (tests.size() < MAX_T) {
    int n = rnd.next(l, r);
    if (nsum + n > MAX_SUM_N) break;
    vector<int> test;
    for (int i = 0; i < n; i++) {
      int h = rnd.next(MIN_H, MAX_H);
      test.push_back(h);
    }
    tests.push_back(test);
    nsum += n;
  }
}

void gen(vector<int> a, int x, int p, int h) {
  if (x != -1) a.push_back(x);
  if (p == 0) {
    vector<int> test;
    for (int i = 0; i < a.size(); i++) {
      test.push_back(a[i]);
    }
    tests.push_back(test);
    nsum += a.size();
    return;
  }
  for (int i = 1; i <= h; i++) {
    gen(a, i, p - 1, h);
  }
}

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);

  int n = atoi(argv[1]), h = atoi(argv[2]);
  int l = atoi(argv[3]), r = atoi(argv[4]);
  /* int n = 8, h = 3, l = 1000, r = 10000; */

  for (int i = 3; i <= n; i++) gen({}, -1, i, h);
  rand(l, r);

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
