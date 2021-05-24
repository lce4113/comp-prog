// ––– CodeForces Round #640: Problem B –––

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
    int n, k;
    cin >> n >> k;

    if (n % 2 == 1 && k % 2 == 0) {
      cout << "NO" << '\n';
      continue;
    }
    if ((n - (k - 1)) % 2 == 1) {
      if (n - k < 0) {
        cout << "NO" << '\n';
        continue;
      }
      cout << "YES" << '\n';
      for (int i = 0; i < k - 1; i++) {
        n--;
        cout << 1 << ' ';
      }
      cout << n << '\n';
    } else {
      if (n - 2 * k < 0) {
        cout << "NO" << '\n';
        continue;
      }
      cout << "YES" << '\n';
      for (int i = 0; i < k - 1; i++) {
        n--;
        n--;
        cout << 2 << ' ';
      }
      cout << n << '\n';
    }
  }
}
