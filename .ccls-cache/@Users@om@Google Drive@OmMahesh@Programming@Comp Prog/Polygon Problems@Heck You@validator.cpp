// ––– "Heck you." - Validator –––

#include "testlib.h"

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
using str = string;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

#define MAXC 100
#define MAXR 100

#define MAXN 1'000'000
#define MAXT 1'000'000

int main(int argc, char* argv[])
{
  registerValidation(argc, argv);

  int n = inf.readInt(1, MAXN, "n");
  inf.readSpace();
  int t = inf.readInt(1, MAXT, "t");
  inf.readEoln();

  for (int i = 1; i <= n; i++) {
    inf.readInt(1, MAXC, "c_i");
    if (i != n) inf.readSpace();
  }
  inf.readEoln();

  for (int i = 1; i <= t; i++) {
    int a = inf.readInt(1, MAXN, "a");
    inf.readSpace();
    inf.readInt(a, MAXN, "b");
    inf.readSpace();
    inf.readInt(1, MAXR, "r");
    inf.readEoln();
  }
  inf.readEof();
}
