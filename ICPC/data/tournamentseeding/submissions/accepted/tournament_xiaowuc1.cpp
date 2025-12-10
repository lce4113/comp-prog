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
  reverse(v.begin(), v.end());
  for(int amt = 2; amt <= n; amt *= 2) {
    int lhs = amt / 2;
    int rhs = amt - 1;
    for(int j = 0; j < amt / 2; j++) {
      if(v[j] - v[lhs] <= k) {
        lhs++;
        ret++;
      }
      else rhs--;
    }
  }
  cout << ret << "\n";
}