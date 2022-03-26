// ––– CodeForces Round #724: Problem C –––

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
    str a;
    cin >> a;

    int d = 0, k = 0;
    map<pi, int> m;
    for (char b : a) {
      if (b == 'D')
        d++;
      else
        k++;
      int g = gcd(d, k);
      cout << ++m[mp(d / g, k / g)] << ' ';
    }
    cout << '\n';
  }
}
