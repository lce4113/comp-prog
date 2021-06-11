// ––– CodeForces Educational Round 110: Problem C –––

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
    str n;
    cin >> n;

    int ans = n.length() * (n.length() + 1) / 2;
    cout << ans << '\n';
    for (int i = 0; i < n.length() - 1; i++) {
      str a = n.substr(i, 1);
      if (a == "?") continue;

      bool B = false;
      int k = i + 1;
      str b = n.substr(k, 1);
      while (b == "?") {
        k++;
        b = n.substr(k, 1);
        if (k >= n.length()) {
          B = true;
          break;
        }
      }
      if (B) {
        continue;
      }

      if (
          ((k - i) % 2 == 1 && a == b) ||
          ((k - i) % 2 == 0 && a != b)
         ) {
        int c = (n.length() - k) * (i + 1);
        cout << i << ' ' << k << ' ' << a << ' ' << b << ' ' << c << '\n';
        ans -= c;
      }
    }

    cout << ans << '\n' << '\n';
  }
}
