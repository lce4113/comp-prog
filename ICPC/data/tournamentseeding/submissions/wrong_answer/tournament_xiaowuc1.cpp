#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  n = 1 << n;
  vector<int> v(n);
  for(auto& x: v) cin >> x;
  int ret = 0;
  sort(v.begin(), v.end());
  for(int i = 0; i < n; i++) {
    for(int j = 0; i + (1 << j) < n; j++) {
      ret += v[i+(1<<j)] - v[i] <= k;
    }
  }
  cout << ret << "\n";
}