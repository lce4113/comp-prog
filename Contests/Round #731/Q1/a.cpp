// ––– CodeForces Round #731: Problem A –––

#include <bits/stdc++.h>

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

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int xa, ya, xb, yb, xf, yf;
    cin >> xa >> ya >> xb >> yb >> xf >> yf;

    if (xa == xb && xb == xf && ((yf < yb && yf > ya) || (yf < ya && yf > yb))) {
      cout << (abs(yb - ya) + 2) << '\n';
      continue;
    }
    if (ya == yb && yb == yf && ((xf < xb && xf > xa) || (xf < xa && xf > xb))) {
      cout << (abs(xb - xa) + 2) << '\n';
      continue;
    }

    cout << (abs(yb - ya) + abs(xb - xa)) << '\n';
  }
}
