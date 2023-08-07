// ––– "Qpwoeirut and the City" - Fastest TLE Solution –––

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

  ll totalHeight = 0;
  vector<int> buildingIndices;
  for (int i = 1; i < n - 1; i += 2) {
    totalHeight += costs[i];
    buildingIndices.push_back(i);
  }

  if (n % 2) {
    cout << totalHeight << '\n';
    return;
  }

  ll minHeight = totalHeight;
  for (int i = n - 3, k = buildingIndices.size() - 1; i >= 1; i -= 2, k--) {
    totalHeight = 0;
    buildingIndices[k]++;
    for (int ind : buildingIndices) {
      totalHeight += costs[ind];
    }
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
