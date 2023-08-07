// ––– "Grid Split" - Test Generator (All Cases) –––

#include "testlib.h"
#include <iostream>
/* #include <bits/stdc++.h> */

using namespace std;

#define MAXT 10'000
#define MAXN 200'000
#define MAXH 1'000'000'000

int t = 0, nsum = 0;
string output = "\n";

vector<vector<int>> all(vector<int> a, int x, int p, int h) {
  if (x != -1) a.push_back(x);
  if (p == 0) return {a};
  vector<vector<int>> ans = {};
  for (int i = 1; i <= h; i++) {
    vector<vector<int>> vs = all(a, i, p - 1, h);
    for (vector<int> v : vs) ans.push_back(v);
  }
  return ans;
}

void gen(int n, int h) {
  vector<vector<int>> vs = all({}, -1, n, h);
  for (vector<int> v1 : vs) {
    for (vector<int> v2 : vs) {
      if (nsum + v1.size() > MAXN) return;
      output += to_string(v1.size()) + "\n";
      for (vector<int> v : {v1, v2}) {
        for (int i = 0; i < v.size(); i++) {
          if (i != 0) output += " ";
          output += to_string(v[i]);
        }
        output += "\n";
      }
      t++;
      if (t == MAXT) return;
      nsum += v1.size();
    }
  }
}

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  int n = atoi(argv[1]), h = atoi(argv[2]);
  for (int i = 1; i <= n; i++) gen(i, h);
  output = to_string(t) + output;
  cout << output;
}
