// ––– 2021 February: Bronze #2 –––

#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;

  int adj[n], comfortable[n];
  pair<int, int> points[n];
  for (int i = 0; i < n; i++) {

    adj[i] = 0;
    comfortable[i] = 0;
    cin >> points[i].first >> points[i].second;

    for (int j = 0; j < i; j++) {
      int x1 = points[i].first;
      int x2 = points[j].first;
      int y1 = points[i].second;
      int y2 = points[j].second;
      if (
          (abs(x1 - x2) == 1 && y1 == y2) || (abs(y1 - y2) == 1 && x1 == x2)) {
        adj[i]++;
        adj[j]++;
      }
    }

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
}
