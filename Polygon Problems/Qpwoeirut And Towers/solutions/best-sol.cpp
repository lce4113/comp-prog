// ––– "Qpwoeirut And Towers" - Acceptable Solution –––

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;

  vector<int> buildings(n);
  for (int &building : buildings) {
    cin >> building;
  }

  vector<int> costs(n - 1);
  for (int i = 1; i < n - 1; i++) {
    int a = buildings[i - 1], b = buildings[i], c = buildings[i + 1];
    costs[i] = max({a, b - 1, c}) - b + 1;
  }

  ll totalBlocks = 0;
  for (int i = 1; i < n - 1; i += 2) {
    totalBlocks += costs[i];
  }

  if (n % 2) {
    cout << totalBlocks << '\n';
    return;
  }

  ll minBlocks = totalBlocks;
  for (int i = n - 3; i >= 1; i -= 2) {
    totalBlocks -= costs[i];
    totalBlocks += costs[i + 1];
    minBlocks = min(minBlocks, totalBlocks);
  }

  cout << minBlocks << '\n';
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}
