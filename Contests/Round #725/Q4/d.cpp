// ––– CodeForces Round #725: Problem D –––

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
    int a, b, k;
    cin >> a >> b >> k;

    if (a == b && k == 1) {
      cout << "NO" << '\n';
      continue;
    }

    int m = 0, n = 0, p = 0;

    for (int i = 2; i * i <= max({ a, b, 4 }); i++) {
      while (a % i == 0 && b % i == 0) {
        p++;
        a /= i;
        b /= i;
      }
      while (a % i == 0) {
        m++;
        a /= i;
      }
      while (b % i == 0) {
        n++;
        b /= i;
      }
    }

    cout << m << ' ' << n << ' ' << p << '\n';

    if (m + n + 2 * p < k) {
      cout << "NO" << '\n';
      continue;
    }

    if (min(1, m) + min(1, n) > k) {
      cout << "NO" << '\n';
      continue;
    }

    cout << "YES" << '\n';
  }
}
