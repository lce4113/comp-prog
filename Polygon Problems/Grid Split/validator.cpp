// ––– "Grid Split" - Validator –––

#include "testlib.h"

using namespace std;

#define MAXT 10'000
#define MAXN 200'000
#define MAXG 1'000'000'000

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);

  int t = inf.readInt(1, MAXT, "t"), nsum = 0;
  inf.readEoln();
  for (int T = 1; T <= t; T++) {
    setTestCase(T);
    int n = inf.readInt(1, MAXN, "n");
    nsum += n;
    inf.readEoln();
    inf.readInts(n, 1, MAXG, "a");
    inf.readEoln();
    inf.readInts(n, 1, MAXG, "b");
    inf.readEoln();
  }
  ensuref(nsum <= MAXN, "Sum of n over all test cases cannot exceed %d", MAXN);
  inf.readEof();
}
