// ––– CodeSprint Beginner 2021: Problem F –––

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

  ll x1, y1, X1, Y1, x2, y2, X2, Y2;
  cin >> x1 >> y1 >> X1 >> Y1 >> x2 >> y2 >> X2 >> Y2;

  long double m1 = (long double)(Y1 - y1) / (X1 - x1);
  long double m2 = (long double)(Y2 - y2) / (X2 - x2);
  if (X1 == x1)
    m1 = -1;
  if (X2 == x2)
    m2 = -1;

  long double b1 = y1 - m1 * x1;
  long double b2 = y2 - m2 * x2;

  /*
    ya = m1 * xa + b1
    ya = m2 * xa + b2
    m1 * xa + b1 = m2 * xa + b2
    (m1 - m2) * xa = b2 - b1
    xa = (b2 - b1) / (m1 - m2)
    ya = m1 * xa + b1
  */

  if (m1 == m2) {
    cout << -1 << '\n';
    return 0;
  }

  long double xa = (b2 - b1) / (m1 - m2);
  long double ya = m1 * xa + b1;
  if (m1 == -1) {
    xa = x1;
    ya = m2 * xa + b2;
  } else if (m2 == -1) {
    xa = x2;
    ya = m1 * xa + b1;
  }

  if (X1 > x1 && xa < x1) {
    cout << -1 << '\n';
    return 0;
  }
  if (X1 < x1 && xa > x1) {
    cout << -1 << '\n';
    return 0;
  }
  if (X2 > x2 && xa < x2) {
    cout << -1 << '\n';
    return 0;
  }
  if (X2 < x2 && xa > x2) {
    cout << -1 << '\n';
    return 0;
  }

  cout << floor(xa) << ' ' << floor(ya) << '\n';
}
