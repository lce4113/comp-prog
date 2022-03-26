// ––– CodeForces Round #729: Problem A –––

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

    int even = 0, odd = 0;
    for (int i = 0; i < 2 * n; i++) {
      int x;
      cin >> x;
      if (x % 2) {
        odd++;
      } else {
        even++;
      }
    }

    if (even == odd) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}
