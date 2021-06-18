// ––– CodeForces Round #726: Problem A –––

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

    int a = 0, sm = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x != 1) {
        sm += x;
        a++;
      }
    }

    if (a == 0 || (double)sm / a == 1) {
      cout << 0 << '\n';
    } else if ((double)sm / a < 1) {
      cout << 1 << '\n';
    } else if ((double)sm / a > 1) {
      cout << sm - a << '\n';
    }
  }
}
