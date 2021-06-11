// ––– CodeForces "Elevator or Stairs?": Problem A –––

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

  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;

  int S = abs(x - y) * t1;
  int E = abs(x - z) * t2 + 3 * t3 + t2 * abs(x - y);

  if (E <= S) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}
