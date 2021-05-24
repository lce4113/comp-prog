// ––– USACO 2017 US Open Bronze: Problem A –––

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
  ifstream cin("lostcow.in");
  ofstream cout("lostcow.out");

  int x, y;
  cin >> x >> y;

  if (x < y) {

    int pos = x, ans = 0;
    for (int i = 1; pos < y; i *= -2) {
      if (i != 1) ans += abs(i) / 2;
      pos = x + i;
      ans += abs(i);
    }

    cout << ans - pos + y << '\n';

    return 0;
  }

  int pos = x, ans = 0;
  for (int i = 1; y < pos; i *= -2) {
    if (i != 1) ans += abs(i) / 2;
    pos = x + i;
    ans += abs(i);
  }

  cout << ans - y + pos << '\n';

}
