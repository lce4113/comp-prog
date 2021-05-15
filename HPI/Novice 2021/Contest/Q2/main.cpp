// HPI 2021: Problem C

#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  int painting[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> painting[i][j];
    }
  }

  int edges = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (painting[i][j] == 1) {
        if (i + 1 >= n) {
          edges++;
        } else if (painting[i + 1][j] == 0) {
          edges++;
        }
        if (i - 1 < 0) {
          edges++;
        } else if (painting[i - 1][j] == 0) {
          edges++;
        }
        if (j + 1 >= m) {
          edges++;
        } else if (painting[i][j + 1] == 0) {
          edges++;
        }
        if (j - 1 < 0) {
          edges++;
        } else if (painting[i][j - 1] == 0) {
          edges++;
        }
      }
    }
  }
  cout << edges;
}
