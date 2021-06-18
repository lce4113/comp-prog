// ––– CodeForces Round #725: Problem G –––

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
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    int ans1 = min(x / a, y / b);
    if (x / a < y / b) {
      ans1 = x / a;
      ans1 += min((x % b) / a, (y % a) / b);
    }

    int ans2 = min(x / b, y / a);
    if (x / b < y / a) {
      ans2 = x / b;
      ans2 += min((x % b) / a, (y % a) / b);
    }

    int ans = max(ans1, ans2);
    cout << ans << '\n';
  }
}
