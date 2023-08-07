// ––– "Qpwoeirut and the City" - Slowest Acceptable Solution –––

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int blocks(vector<int> &buildings, int ind) {
  int a = buildings[ind - 1], b = buildings[ind], c = buildings[ind + 1];
  return max({a, b - 1, c}) - b + 1;
}

void solve() {
  int n;
  cin >> n;

  vector<int> buildings(n);
  for (int &building : buildings) {
    cin >> building;
  }

  ll totalHeight = 0;
  for (int i = 1; i < n - 1; i += 2) {
    totalHeight += blocks(buildings, i);
  }

  if (n % 2) {
    cout << totalHeight << '\n';
    return;
  }

  ll minHeight = totalHeight;
  for (int i = n - 3; i >= 1; i -= 2) {
    totalHeight -= blocks(buildings, i);
    totalHeight += blocks(buildings, i + 1);
    minHeight = min(minHeight, totalHeight);
  }

  cout << minHeight << '\n';
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}
