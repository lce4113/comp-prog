// ––– CodeForces Round #730: Problem C –––

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

long double ans, v;

bool eq(long double a, long double b, long double eps = 0.00001)
{
  return (abs(a - b) < eps);
}

void f(long double c, long double m, long double p, long double i, long double prob)
{
  ans += prob * p * i;
  /* cout << prob * p * i << '\n'; */
  if (!eq(c, 0)) {
    if (eq(m, 0)) {
      f(max((long double)0, c - v), 0, p + min(c, v), i + 1, prob * c);
    } else {
      f(max((long double)0, c - v), m + min(c / 2, v / 2), p + min(c / 2, v / 2), i + 1, prob * c);
    }
  }
  if (!eq(m, 0)) {
    if (eq(c, 0)) {
      f(0, max((long double)0, m - v), p + min(m, v), i + 1, prob * m);
    } else {
      f(c + min(m / 2, v / 2), max((long double)0, m - v), p + min(m / 2, v / 2), i + 1, prob * m);
    }
  }
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    long double c, m, p;
    cin >> c >> m >> p >> v;

    ans = 0;
    f(c, m, p, 1, 1);

    cout << setprecision(13) << ans << '\n';
  }
}
