// ––– CodeSprint Beginner 2021: Problem B –––

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

  ll t;
  cin >> t;
  while (t--) {
    ll n, m, a, b, d;
    cin >> n >> m >> a >> b >> d;

    ll T = b + d + (b - a);

    /* if (T % n <= n - m) */
    /* if (T % n > 0 && T % n < n - m) */
    /* if (T % n < n - m) */
    if (T % n > 0 && T % n <= n - m)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
