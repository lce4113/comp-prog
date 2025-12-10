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

int main(int argc, char* argv[])
{
  registerValidation(argc, argv);

  int n = inf.readInt(1, 100'000, "n");
  int t = inf.readInt(1, 1'000'000, "t");

  for (int i = 0; i < n; i++) {
    inf.readInt(1, 100, "c_i");
    inf.readSpace();
  }
  for (int i = 0; i < t; i++) {
    int a = inf.readInt(1, 100, "a");
    inf.readSpace();
    inf.readInt(a, 100, "b");
    inf.readSpace();
    inf.readInt(a, 100, "r");
    inf.readEoln();
  }
  inf.readEof();
}
