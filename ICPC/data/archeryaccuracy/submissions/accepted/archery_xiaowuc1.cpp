#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

const double EPS = 1e-9;

int main() {
  map<tuple<double, int, int>, double> rrefdp;
  auto win = [&](double up, int src, int amt) -> double {
    tuple<double, int, int> key = {up, src, amt};
    if(rrefdp.count(key)) return rrefdp[key];
    vector<vector<double>> dp(amt+1);
    for(auto& x: dp) x.resize(amt+2);
    for(int i = 0; i <= amt; i++) {
      dp[i][i] = 1;
      if(i == 0) {
        continue;
      }
      if(i == amt) {
        dp[i].back() = 1;
        continue;
      }
      dp[i][i+1] = -up;
      dp[i][i-1] = -(1-up);
    }
    int rnk = 0;
    for(int j = 0; j <= amt; j++) {
      bool found = false;
      for(int i = rnk; i < dp.size(); i++) {
        if(fabs(dp[i][j]) > EPS) {
          if(i != rnk) {
            swap(dp[i], dp[rnk]);
          }
          found = true;
          break;
        }
      }
      assert(found);
      double scale = dp[rnk][j];
      for(int a = 0; a < dp[rnk].size(); a++) dp[rnk][a] /= scale;
      for(int x = 0; x <= amt; x++) {
        if(x == rnk) continue;
        double scale = -dp[x][j];
        for(int y = 0; y < dp[x].size(); y++) dp[x][y] += scale * dp[rnk][y];
      }
      rnk++;
    }
    assert(rnk == amt+1);
    return rrefdp[key] = dp[src].back();
  };
  int n;
  cin >> n;
  vector<double> p(n);
  for(auto& x: p) cin >> x;
  vector<int> target(n);
  for(auto& x: target) cin >> x;
  vector<double> dp(1 << n);
  for(int mask = 0; mask < (1<<n); mask++) {
    int idx = __builtin_popcount(mask);
    for(int i = 0; i < n; i++) {
      if(mask&(1<<i)) continue;
      int origT = (idx == 0 ? 0 : target[idx-1]);
      double cand = 0;
      cand += dp[mask] * win(p[i], target[idx] + origT, target[idx] + target[idx]);
      cand += (1-dp[mask]) * win(p[i], target[idx] - origT, target[idx] + target[idx]);
      dp[mask|(1<<i)] = max(dp[mask|(1<<i)], cand);
    }
  }
  cout << fixed << setprecision(17) << dp.back() << "\n";
}