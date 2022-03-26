// ––– CodeForces LATOKEN Round 1: Problem A –––

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
    int n, m;
    cin >> n >> m;

    char arr[n][m], a = -1;
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < m; k++) {
        char x;
        cin >> x;
        arr[i][k] = x;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int k = 0; k < m; k++) {
        int x = arr[i][k];
        if (x == 'R') {
          int b = abs(k - i) % 2;
          if (a == -1) {
            a = b;
          } else if (a != b) {
            goto done;
          }
        } else if (x == 'W') {
          int b = 1 - (abs(k - i) % 2);
          if (a == -1) {
            a = b;
          } else if (a != b) {
            goto done;
          }
        }
      }
    }

    if (a == -1) {
      a = 0;
    }

    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < m; k++) {
        int b = abs(k - i) % 2;
        cout << ((a == 1 && b == 1 || a == 0 && b == 0) ? 'R' : 'W');
      }
      cout << '\n';
    }
    continue;
done:
    cout << "NO" << '\n';
  }
}
