// ––– CodeForces Round #720: Problem A –––

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
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;

    if (b == 1) {
      cout << "NO" << endl;
      continue;
    }

    if (b == 2) {
      cout << "YES" << endl;
      cout << 1 * a << ' ' << 3 * a << ' ' << 4 * a << endl;
      continue;
    }

    cout << "YES" << endl;
    cout << a << ' ' << a * (b - 1) << ' ' << a * b << endl;
    /* cout << a << ' ' << a * b << ' ' << a * (b + 1) << endl; */
    continue;
  }
}
