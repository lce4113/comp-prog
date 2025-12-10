#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> values(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i];
  }
  vector<int> ans;
  for (int k = 2; k <= n; k++) {
    if (n % k) continue;
    int s = n / k;
    int prevgMax = 0;
    bool ok = true;
    for (int g = 0; g < k; g++) {
      int gs = g * s, ge = (g + 1) * s;
      int gMin = n + 1, gMax = 0;
      for (int i = gs; i < ge; i++) {
        gMin = min(gMin, values[i]);
        gMax = max(gMax, values[i]);
      }
      if (prevgMax > gMin) {
        ok = false;
        break;
      }
      prevgMax = gMax;
    }
    if (ok) ans.push_back(k);
  }
  if (ans.size() == 0) cout << -1 << endl;
  else {
    for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << endl;
  }
  return 0;
}
