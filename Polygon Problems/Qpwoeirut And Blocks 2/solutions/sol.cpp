// ––– HEADER –––

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
    ll n, x;
    cin >> n >> x;

    if (x % 2) {
      cout << "No" << '\n';
      return 0;
    }

    if (x > 2 * n + 2) {
      cout << "No" << '\n';
      return 0;
    }

    ll a = sqrt(n), mn;
    if (n == a * a) {
      mn = 4 * a;
    } else if (n <= a * (a + 1)) {
      mn = 4 * a + 2;
    } else {
      mn = 4 * a + 4;
    }

    if (x < mn) {
      cout << "No" << '\n';
      return 0;
    }

    cout << "Yes" << '\n';
  }
}
