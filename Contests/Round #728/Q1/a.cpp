// ––– CodeForces Round #728: Problem A –––

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

    if (n % 2 == 1) {
      for (int i = 0; i < (n - 3) / 2; i++) {
        cout << 2 * i + 2 << ' ';
        cout << 2 * i + 1 << ' ';
      }
      cout << n - 0 << ' ';
      cout << n - 2 << ' ';
      cout << n - 1 << ' ';
    } else {
      for (int i = 0; i < n / 2; i++) {
        cout << 2 * i + 2 << ' ';
        cout << 2 * i + 1 << ' ';
      }
    }
    cout << '\n';
  }
}
