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

const ll MAXT = 1e4;
const ll MAXN = 1e18;
const ll MAXX = 1e18;

int main(int argc, char* argv[])
{
  registerValidation(argc, argv);

  int t = inf.readLong(1, MAXT, "t");
  inf.readEoln();

  for (int i = 1; i <= t; i++) {
    setTestCase(i);
    int n = inf.readLong(1, MAXN, "n");
    inf.readSpace();
    int x = inf.readLong(1, MAXX, "x");
    inf.readEoln();
  }

  inf.readEof();
}
