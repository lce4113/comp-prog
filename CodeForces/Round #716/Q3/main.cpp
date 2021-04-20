// ––– Round #716: Problem C –––

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
  ll n;
  cin >> n;

  ll arr[100000], sz = 0, prod = 1;
  for (int i = 1; i <= n; i++) {
    if (gcd(i, n) == 1) {
      arr[sz++] = i;
      prod *= i;
      prod = prod % n;
    }
  }

  ll num = prod % n;

  if (num == 1) {
    cout << sz << endl;
    for (ll i = 0; i < sz; i++) {
      cout << arr[i] << ' ';
    }
  } else {
    cout << sz - 1 << endl;
    for (ll i = 0; i < sz; i++) {
      if (arr[i] != num)
        cout << arr[i] << ' ';
    }
  }
}
