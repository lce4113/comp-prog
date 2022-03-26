// ––– CodeForces Contest 1100, Problem C: "NN and the Optical Illusion" –––

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

  int n, r;
  cin >> n >> r;

  double a = abs(sin(3.141592653589753238 / n));
  double ans = r * a / (1 - a);

  cout << setprecision(8) << ans << '\n';
}
