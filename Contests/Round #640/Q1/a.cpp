// ––– CodeForces Round #640: Problem A –––

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

    int a = -1, b;
    vi d;
    while (n > 0) {
      a++;
      b = n % 10;
      if (b != 0) {
        d.pb(b * pow(10, a));
      }
      n /= 10;
    }
    cout << d.size() << '\n';
    for (int i = 0; i < d.size(); i++) {
      cout << d[i] << ' ';
    }
    cout << '\n';
  }
}
