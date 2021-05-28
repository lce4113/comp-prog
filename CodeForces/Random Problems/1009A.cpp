// ––– CodeForces Game Shopping: Problem A –––

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

  int n, m;
  cin >> n >> m;

  vi c;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    c.pb(x);
  }

  vi a;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    a.pb(x);
  }

  int p = 0;
  int ans = 0;
  for (int i = 0; i < a.size(); i++) {
    for (int k = p; k < c.size(); k++) {
      if (a[i] >= c[k]) {
        p = k + 1;
        ans++;
        break;
      }
      if (k == c.size() - 1) {
        cout << ans << '\n';
        return 0;
      }
    }
    if (p == n)
      break;
  }

  cout << ans << '\n';
}
