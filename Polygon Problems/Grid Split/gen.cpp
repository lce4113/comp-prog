// ––– "Grid Split" - Test Generator (Main) –––

#include "testlib.h"
#include <iostream>

using namespace std;

#define MAXT 10'000
#define MAXN 200'000
#define MAXH 1'000'000'000

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);

  int n1 = atoi(argv[1]), n2 = atoi(argv[2]);

  int t = 0, nsum = 0;
  string output = "\n";
  while (t < MAXT) {
    int n = rnd.next(n1, n2);
    if (nsum + n > MAXN) break;
    output += to_string(n) + "\n";
    for (int x = 0; x < 2; x++) {
      for (int i = 0; i < n; i++) {
        int h = rnd.next(1, MAXH);
        if (i != 0) output += " ";
        output += to_string(h);
      }
      output += "\n";
    }
    nsum += n, t++;
  }
  output = to_string(t) + output;
  cout << output;
}
