// ––– "Qpwoeirut and Towers" - Test Generator (All Cases) –––

#include "testlib.h"
#include <iostream>
/* #include <bits/stdc++.h> */

using namespace std;

#define MAXT 10'000
#define MAXN 200'000
#define MAXH 1'000'000'000

int n, h, t = 0;
string output = "\n";

void gen(vector<int> a, int x, int p) {
  if (x != -1) a.push_back(x);
  if (p == 0) {
    output += to_string(a.size());
    output += "\n";
    for (int i = 0; i < a.size(); i++) {
      if (i != 0) output += " ";
      output += to_string(a[i]);
    }
    output += "\n";
    t++;
    return;
  }
  for (int i = 1; i <= h; i++) {
    gen(a, i, p - 1);
  }
}

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);

  n = atoi(argv[1]), h = atoi(argv[2]);
  for (int i = 3; i <= n; i++) gen({}, -1, i);
  output = to_string(t) + output;
  cout << output;
}
