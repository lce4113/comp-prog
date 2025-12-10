#include <iostream>
#include <vector>
using namespace std ;
using ll = long long ;
const int MAXN = 1024 ;
int b[MAXN][MAXN] ;
ll early[MAXN][MAXN] ;
ll dp[4][MAXN] ;
const ll INF = 1000000000000000000LL ;
int main() {
   int n, k ;
   cin >> n >> k ;
   vector<vector<pair<int, int>>> q(k) ;
   for (int i=0; i<n; i++)
      for (int j=0; j<n; j++) {
         int v ;
         cin >> v ;
         b[i][j] = v - 1 ;
         early[i][j] = INF ;
         q[v-1].push_back({i,j}) ;
      }
   int r = 0 ;
   int w = 2 ;
   for (int m=0; m<n; m++)
      dp[r][m] = dp[r+1][m] = INF ;
   for (int i=0; i<(int)q[0].size(); i++) {
      early[q[0][i].first][q[0][i].second] = 0 ;
      dp[r][q[0][i].first] = 0 ;
      dp[r+1][q[0][i].second] = 0 ;
   }
   for (int i=1; i<k; i++) {
      for (int m=0; m<n; m++)
         dp[w][m] = dp[w+1][m] = INF ;
      for (int j=0; j<(int)q[i].size(); j++) {
         int x = q[i][j].first ;
         int y = q[i][j].second ;
         ll arr = INF ;
         for (int m=0; m<n; m++)
            arr = min(arr, min(dp[r][m] + (m-x)*(m-x),
                               dp[r+1][m] + (m-y)*(m-y))) ;
         dp[w][x] = min(dp[w][x], arr) ;
         dp[w+1][y] = min(dp[w][y], arr) ;
      }
      swap(r, w) ;
   }
   ll lo = INF ;
   for (int m=0; m<n; m++)
      lo = min(lo, min(dp[r][m], dp[r+1][m])) ;
   if (lo == INF)
      cout << -1 << endl ;
   else
      cout << lo << endl ;
}
