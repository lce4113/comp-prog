// CodeForces Round #922: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MAX_B 60

bool get_bit(int n, int i) { return n & (1ll << i); }

void solve() {
  int a, b, r;
  cin >> a >> b >> r;
  /* cout << a << ' ' << b << ' ' << r << '\n'; */

  if (a < b) swap(a, b);

  int x = 0, first_bit = 1;
  for (int i = MAX_B - 1; i >= 0; i--) {
    int ba = get_bit(a, i), bb = get_bit(b, i);
    /* cout << ba << ' ' << bb << '\n'; */
    int curr_bin = 1ll << i;

    if (ba != bb) {
      if (first_bit) {
        first_bit = 0;
      } else if (!bb && x + curr_bin <= r) {
        x += curr_bin;
      }
    }
  }

  /* cout << "x: " << x << '\n'; */

  cout << abs((a ^ x) - (b ^ x)) << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
