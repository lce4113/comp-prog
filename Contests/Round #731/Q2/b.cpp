// ––– CodeForces Round #731: Problem B –––

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
    str a;
    cin >> a;

    bool b = false;
    for (int i = 0; i < a.length() - 1; i++) {
      if (a[i] == 'a') {
        b = true;
      }

      if (b && a[i] >= a[i + 1]) {
        goto done;
      }
      if (!b && a[i] <= a[i + 1]) {
        goto done;
      }
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < a.length(); i++) {
      if (a[i] - 'a' != i) {
        goto done;
      }
    }

    cout << "YES" << '\n';
    continue;
  done:
    cout << "NO" << '\n';
  }
}
