// ––– CodeForces Anton and Digits: Problem B –––

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

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int x = min({ a, c, d });
  int ans = 256 * x;
  a -= x;
  c -= x;
  d -= x;

  ans += 32 * min(a, b);
  cout << ans << '\n';
}
