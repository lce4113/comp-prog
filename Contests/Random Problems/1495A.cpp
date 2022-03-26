// ––– CodeForces Contest 1495, Problem A: "Diamond Miner" –––

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
    int n;
    cin >> n;

    vl vec1, vec2;
    for (int i = 0; i < 2 * n; i++) {
      ll x, y;
      cin >> x >> y;

      if (x == 0) {
        vec1.pb(y * y);
      }
      if (y == 0) {
        vec2.pb(x * x);
      }
    }

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    long double S = 0;
    for (int i = 0; i < n; i++) {
      S += sqrt(vec1[i] + vec2[i]);
    }

    cout << setprecision(16) << S << '\n';
  }
}
