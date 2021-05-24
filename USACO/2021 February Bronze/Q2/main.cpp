// ––– 2021 February: Bronze #2 –––

#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;

  int adj[n], comfortable[n];
  pair<int, int> points[n];
  int grid[1000][1000];
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      grid[j][i] = -1;
    }
  }

  int t;
  for (int i = 0; i < n; i++) {

    int x, y;
    cin >> x >> y;
    points[i].first = x;
    points[i].second = y;
    grid[y][x] = i;

    adj[i] = 0;

    t = grid[y + 1][x];
    if (t >= 0) {
      adj[i]++;
      adj[t]++;
    }
    t = grid[y - 1][x];
    if (t >= 0) {
      adj[i]++;
      adj[t]++;
    }
    t = grid[y][x + 1];
    if (t >= 0) {
      adj[i]++;
      adj[t]++;
    }
    t = grid[y][x - 1];
    if (t >= 0) {
      adj[i]++;
      adj[t]++;
    }

    comfortable[i] = 0;
    for (int j = 0; j < i; j++) {
      if (adj[j] == 3)
        comfortable[i]++;
    }
  }

  string out = to_string(comfortable[0]);
  for (int i = 1; i < n; i++) {
    out += "\n";
    out += to_string(comfortable[i]);
  }

  cout << out;

  return 0;
}
