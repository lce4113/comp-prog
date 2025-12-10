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
  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int n;
    cin >> n;

    char arr[n][n];
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        cin >> arr[j][k];
        if (arr[j][k] == '*') {
          if (x1 == -1) {
            x1 = k;
            y1 = j;
          } else {
            x2 = k;
            y2 = j;
          }
        }
      }
    }

    if (x1 != x2 && y1 != y2) {
      arr[y2][x1] = '*';
      arr[y1][x2] = '*';
    }

    if (x1 == x2) {
      if (x1 != n - 1) {
        arr[y1][x1 + 1] = '*';
        arr[y2][x2 + 1] = '*';
      } else if (x1 != 0) {
        arr[y1][x1 - 1] = '*';
        arr[y2][x2 - 1] = '*';
      }
    } else if (y1 == y2) {
      if (y1 != n - 1) {
        arr[y1 + 1][x1] = '*';
        arr[y2 + 1][x2] = '*';
      } else if (y1 != 0) {
        arr[y1 - 1][x1] = '*';
        arr[y2 - 1][x2] = '*';
      }
    }

    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        cout << arr[j][k];
      }
      cout << endl;
    }
  }
}
