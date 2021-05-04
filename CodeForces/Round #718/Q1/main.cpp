// ––– Round #718: Problem A –––

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
    ll a;
    cin >> a;
    if (a % 2050 != 0) {
      cout << -1 << endl;
      continue;
    }
    a /= 2050;
    ll b = 0;
    while (a > 0) {
      b += a % 10;
      a /= 10;
    }
    cout << b << endl;
  }
}
