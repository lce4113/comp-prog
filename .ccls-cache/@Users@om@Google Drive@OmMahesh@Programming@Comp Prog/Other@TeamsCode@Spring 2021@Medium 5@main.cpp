// ––– HEADER –––

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

#define MAXN 100

const int MOD = 1e9 + 7;
int ans = 0, len = MAXN * MAXN;

int check(int arr[MAXN][MAXN], int x, int y, int n, int m, int a)
{
  int dx[4] = { 0, 0, 1, -1 };
  int dy[4] = { 1, -1, 0, 0 };

  int sum = 0;
  for (int i = 0; i < 4; i++) {
    int x2 = x + dx[i];
    int y2 = y + dy[i];

    if (x2 == n - 1 && y2 == m - 1) {
      if (a == len) {
        ans = (ans + 1) % MOD;
      } else if (a < len) {
        ans = 1;
        len = a;
      }
      continue;
    }
    if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) {
      continue;
    }
    if (arr[x2][y2] == 1 || arr[x2][y2] == 2) {
      continue;
    }

    arr[x2][y2] = 2;

    int arr2[MAXN][MAXN];
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < m; k++) {
        arr2[i][k] = arr[i][k];
      }
    }

    sum = (sum + check(arr2, x2, y2, n, m, a + 1)) % MOD;
  }
  return sum;
}

int main()
{
  int n, m;
  cin >> n >> m;

  int arr[MAXN][MAXN];
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < m; k++) {
      cin >> arr[i][k];
    }
  }
  arr[0][0] = 2;

  int ans = check(arr, 0, 0, n, m, 0);
  cout << ans;
}
