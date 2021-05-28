// ––– CodeForces Unique Number: Problem C –––

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

    if (n > 45) {
      cout << -1 << '\n';
      continue;
    }

    vi a;
    int b = 10;
    while (n > 0) {
      b--;
      n -= b;
      a.pb(b);
    }
    n += b;
    a.pop_back();
    if (n != 0) {
      a.pb(n);
    }

    for (int i = a.size() - 1; i >= 0; i--) {
      cout << a[i];
    }
    cout << '\n';

    cout << '\n';
  }
}
