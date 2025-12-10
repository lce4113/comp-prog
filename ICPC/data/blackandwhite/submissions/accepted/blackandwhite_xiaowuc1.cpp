#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<double> p(n);
  for(auto& x: p) cin >> x;
  vector<double> pos(1<<n, 1.0);
  vector<double> neg(1<<n, 1.0);
  for(int mask = 0; mask < (1<<n); mask++) {
    for(int i = 0; i < n; i++) {
      if((mask&(1<<i)) != 0) {
        pos[mask] *= p[i];
        neg[mask] *= 1 - p[i];
      }
    }
  }
  vector<double> dp(1 << n);
  vector<double> chance(1 << n);
  chance.back() = 1;
  double ret = 0;
  for(int mask = (1<<n)-1; mask >= 0; mask--) {
    if(__builtin_popcount(mask) == 2) ret += dp[mask];
    if(__builtin_popcount(mask) <= 2) continue;
    dp[mask] /= chance[mask];
    vector<pair<int, double>> updates;
    double term = 0;
    for(int i = 0; i < n; i++) {
      if((mask&(1<<i)) == 0) continue;
      double up = pos[mask] / p[i] * (1 - p[i]);
      double down = neg[mask] / (1 - p[i]) * p[i];
      updates.emplace_back(i, up+down);
      term += updates.back().second;
    }
    double gain = 1 / (term);
    for(auto [x, pp]: updates) {
      double scalep = pp / term * chance[mask];
      dp[mask ^ (1 << x)] += (dp[mask] + gain) * scalep;
      chance[mask ^ (1 << x)] += scalep;
    }
  }
  cout << fixed << setprecision(17) << ret << "\n";
}