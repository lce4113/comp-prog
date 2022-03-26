// ––– CodeForces Round #725: Problem F –––

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
    int l, r;
    cin >> l >> r;

    int a = 0;
    while (r > 0) {
      a += r;
      r /= 10;
    }
    while (l > 0) {
      a -= l;
      l /= 10;
    }

    cout << a << '\n';
  }
}
