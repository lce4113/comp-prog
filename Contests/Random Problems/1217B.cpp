// ––– CodeForces Contest 1217, Problem B: "Zmei Gorynich" –––

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

    ll m1 = -1, m2 = -1;
    for (int i = 0; i < n; i++) {
      ll a, b;
      cin >> a >> b;
      if (a - b > m1)
        m1 = a - b;
      if (a > m2)
        m2 = a;
    }

    if (x <= m2) {
      cout << 1 << '\n';
      continue;
    }
    if (m1 <= 0) {
      cout << -1 << '\n';
      continue;
    }

    ll a = ceil((double)abs(m2 - x) / m1);
    cout << a + 1 << '\n';
  }
}
