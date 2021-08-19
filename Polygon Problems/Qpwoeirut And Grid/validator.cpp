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

#define MAXT 1'000
#define MAXN 1'000'000'000
#define MAXA 100

int main(int argc, char* argv[])
{
  registerValidation(argc, argv);

  int t = inf.readInt(1, MAXT, "t");
  inf.readEoln();
  while (t--) {
    int n = inf.readInt(1, MAXN, "n");
    inf.readEoln();

    for (int i = 1; i <= 2; i++) {
      for (int k = 1; k <= n; k++) {
        inf.readInt(1, MAXA, "a_i");
        if (k != n) inf.readSpace();
      }
      inf.readEoln();
    }
  }
  inf.readEof();
}
