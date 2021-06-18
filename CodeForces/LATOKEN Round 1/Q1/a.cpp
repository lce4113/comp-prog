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

    char arr[n][m];
    int a = -1, b;
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < m; k++) {
        char x;
        cin >> x;
        arr[i][k] = x;
        b = (i - k) % 2;
        if (x == 'R') {
          if (a != -1 && a != b) {
            goto done;
          }
          a = b;
        }
        if (x == 'W') {
          if (a != -1 && a != 1 - b) {
            goto done;
          }
          a = 1 - b;
        }
      }
    }

    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < m; k++) {
        if (arr[i][k] == '.') {
          int b = (i - k) % 2;
          if ((a == 1 && b == 1) || (a == 0 && b == 0)) {
            cout << "R";
          } else {
            cout << "W";
          }
        } else {
          cout << arr[i][k];
        }
      }
      cout << '\n';
    }
    cout << '\n';
    continue;
done:
    cout << "NO" << '\n';

  }
}
