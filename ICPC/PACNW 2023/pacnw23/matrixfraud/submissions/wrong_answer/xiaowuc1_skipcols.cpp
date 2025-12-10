#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void transpose(vector<vector<char>>& g) {
  int r = g.size();
  int c = g[0].size();
  vector<vector<char>> ng(c);
  for(int i = 0; i < c; i++) {
    ng[i].resize(r);
    for(int j = 0; j < r; j++) ng[i][j] = g[j][i];
  }
  g.swap(ng);
}

void genpsum(vector<int>& dp, const vector<char>& v) {
  dp.resize(v.size()+1);
  for(int i = 0; i < v.size(); i++) {
    dp[i+1] = dp[i] + (v[i] == '1');
  }
}

int getops(vector<int>& dp, int a, int b) {
  int zeroinside = (b-a+1) - (dp[b+1] - dp[a]);
  int oneoutside = dp[a] + (dp.back() - dp[b+1]);
  return zeroinside + oneoutside;
}

int main() {
  int r, c;
  cin >> r >> c;
  vector<vector<char>> g(r);
  for(auto& x: g) {
    x.resize(c);
    for(auto& y: x) cin >> y;
  }
  if(c > r) transpose(g);
  r = g.size();
  c = g[0].size();
  vector<vector<int>> dp(c);
  for(auto& x: dp) x.assign(c, 1e9);
  {
    vector<int> psum;
    genpsum(psum, g[0]);
    for(int a = 0; a < c; a++) dp[0][a] = getops(psum, 0, a);
  }
  for(int i = 1; i < r; i++) {
    vector<int> psum;
    genpsum(psum, g[i]);
    vector<vector<int>> ndp(c);
    for(auto& x: ndp) x.assign(c, 1e9);
    // WA: not every column has a 1
    for(int a = 0; a < ndp.size(); a++) for(int b = 0; b < ndp[a].size(); b++) {
      if(a) dp[a][b] = min(dp[a][b], dp[a-1][b]);
      if(b) dp[a][b] = min(dp[a][b], dp[a][b-1]);
    }
    for(int a = 0; a < ndp.size(); a++) for(int b = 0; b < ndp.size(); b++) {
      ndp[a][b] = dp[a][b] + getops(psum, a, b);
    }
    dp.swap(ndp);
  }
  int ret = 1e9;
  for(int a = 0; a < c; a++) ret = min(ret, dp[a][c-1]);
  cout << ret << "\n";
}