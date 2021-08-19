// ––– HEADER –––

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

  ll n;
  cin >> n;

  ll a = sqrt(n);
  if (n == a * a) {
    cout << 4 * a << '\n';
  } else if (n <= a * (a + 1)) {
    cout << 4 * a + 2 << '\n';
  } else {
    cout << 4 * a + 4 << '\n';
  }
}
