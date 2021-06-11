// ––– CodeForces Round #712: Problem A –––

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
    str x;
    cin >> x;

    int n = x.length();
    for (int i = 0; i < n; i++) {
      str a = x.substr(n - i - 1, 1);
      if (a != "a") {
        cout << "YES" << '\n';
        cout << x.substr(0, i) + "a" + x.substr(i, n - i) << '\n';
        goto done;
      }
    }

    cout << "NO" << '\n';
  done:
    continue;
  }
}
