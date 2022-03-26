// ––– "Qpwoeirut and Towers" - Validator –––

#include "testlib.h"

using namespace std;

#define MAXT 10'000
#define MAXN 200'000
#define MAXH 1'000'000'000

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);

  int t = inf.readInt(1, MAXT, "t"), sm = 0;
  inf.readEoln();
  for (int T = 1; T <= t; T++) {
    setTestCase(T);
    int n = inf.readInt(3, MAXN, "n");
    sm += n;
    inf.readEoln();
    inf.readInts(n, 1, MAXH, "h");
    inf.readEoln();
  }
  ensuref(sm <= MAXN, "Sum of n over all test cases cannot exceed %d", MAXN);
  inf.readEof();
}
