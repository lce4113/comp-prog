// ––– "Qpwoeirut and the City" - Validator –––

#include "testlib.h"

using namespace std;

#define MAX_T 10'000
#define MIN_N 3
#define MAX_N 100'000
#define MAX_SUM_N 200'000
#define MIN_H 1
#define MAX_H 1'000'000'000

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);

  int t = inf.readInt(1, MAX_T, "t"), sm = 0;
  inf.readEoln();
  for (int T = 1; T <= t; T++) {
    setTestCase(T);
    int n = inf.readInt(MIN_N, MAX_N, "n");
    sm += n;
    inf.readEoln();
    inf.readInts(n, MIN_H, MAX_H, "h");
    inf.readEoln();
    ensuref(sm <= MAX_SUM_N, "Sum of n over all test cases cannot exceed %d", MAX_SUM_N);
  }
  inf.readEof();
}
