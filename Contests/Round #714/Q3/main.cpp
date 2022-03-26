// ––– Round #714: Problem C –––

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

map<pair<int, int>, int> totals = {};

int getTotal(int o, int d)
{
  if (o - (10 - d) < 0)
    return 1;
  cout << totals[mp(d, o)] << endl;
  if (totals[mp(d, o)] != 0) {
    return totals[mp(d, o)];
    cout << 1;
  }
  int total = getTotal(o - (10 - d), 1) + getTotal(o - (11 - d), 1);
  totals[mp(d, o)] = total;
  return total;
}

int main()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int num, o, ans = 0;
    cin >> num >> o;

    for (int j = 0; num > 0; j++) {
      int digit = num % 10;
      num /= 10;
      ans += getTotal(o, digit);
    }

    cout << ans << endl;
  }
}
