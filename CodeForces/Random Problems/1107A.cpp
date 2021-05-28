// ––– CodeForces Digits Sequence Dividing: Problem A –––

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
    str a;
    cin >> a;

    str x, y;
    if (n % 2 == 1) {
      x = a.substr(0, n / 2);
      y = a.substr(n / 2, n - n / 2);
    } else if (n > 2) {
      x = a.substr(0, n / 2 - 1);
      y = a.substr(n / 2 - 1, n - n / 2 + 1);
    } else {
      x = a.substr(0, 1);
      y = a.substr(1, 1);
      if (x >= y) {
        cout << "NO" << '\n';
        continue;
      }
    }
    cout << "YES" << '\n';
    cout << 2 << '\n';
    cout << x << ' ' << y << '\n';
  }
}
