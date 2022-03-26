// ––– "Qpwoeirut and Towers" - Test Generator –––

#include "testlib.h"
#include <iostream>

using namespace std;

#define MAXT 10'000
#define MAXN 200'000
#define MAXH 1'000'000'000

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);

  int n1 = atoi(argv[1]), n2 = atoi(argv[2]);

  int t = 0, sm = 0;
  string output = "\n";
  while (t < MAXT) {
    int n = rnd.next(n1, n2);
    if (sm + n > MAXN) break;
    output += to_string(n) + "\n";
    for (int i = 0; i < n; i++) {
      int h = rnd.next(0, MAXH);
      output += to_string(h);
      if (i != n - 1) output += " ";
    }
    output += '\n';
    sm += n, t++;
  }
  output = to_string(t) + output;
  cout << output;
}
