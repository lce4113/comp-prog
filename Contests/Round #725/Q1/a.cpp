// ––– CodeForces Round #725: Problem A –––

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

    int m1 = -1, m2 = 10000;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x > m1) {
        m1 = x;
        a = i;
      }
      if (x < m2) {
        m2 = x;
        b = i;
      }
    }

    int ans = min({ max(a, b) + 1, n - min(a, b), min(a, b) + 1 + n - max(a, b) });
    cout << ans << '\n';
  }
}
