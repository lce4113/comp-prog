// ––– CodeForces Round #729: Problem B –––

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
    int n, a, b;
    cin >> n >> a >> b;

    if (a == 1) {
      if ((n - 1) % b == 0) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
      continue;
    }

    for (ll i = 1; i <= n; i *= a) {
      if (n % b == i % b) {
        goto done;
      }
    }

    cout << "NO" << '\n';
    continue;
  done:
    cout << "YES" << '\n';
  }
}
