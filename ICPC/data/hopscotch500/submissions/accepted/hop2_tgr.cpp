#include <iostream>
#include <vector>
using namespace std ;
using ll = long long ;
const int MAXN = 1024 ;
int b[MAXN][MAXN] ;
ll early[MAXN][MAXN] ;
ll dp[2][MAXN] ;
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
   for (int i=0; i<(int)q[0].size(); i++)
      early[q[0][i].first][q[0][i].second] = 0 ;
   for (int i=1; i<k; i++) {
      if ((int)q[i-1].size() < n) {
         for (int j=0; j<(int)q[i].size(); j++) {
            int x = q[i][j].first ;
            int y = q[i][j].second ;
            ll arr = INF ;
            for (int m=0; m<(int)q[i-1].size(); m++) {
               int x0 = q[i-1][m].first ;
               int y0 = q[i-1][m].second ;
               arr = min(arr, early[x0][y0] + min((x-x0)*(x-x0), (y-y0)*(y-y0))) ;
            }
            early[x][y] = arr ;
         }
      } else {
         for (int m=0; m<n; m++)
            dp[0][m] = dp[1][m] = INF ;
         for (int j=0; j<(int)q[i-1].size(); j++) {
            int x = q[i-1][j].first ;
            int y = q[i-1][j].second ;
            dp[0][x] = min(dp[0][x], early[x][y]) ;
            dp[1][y] = min(dp[1][y], early[x][y]) ;
         }
         for (int j=0; j<(int)q[i].size(); j++) {
            int x = q[i][j].first ;
            int y = q[i][j].second ;
            ll arr = INF ;
            for (int m=0; m<n; m++)
               arr = min(arr, min(dp[0][m] + (m-x)*(m-x),
                                  dp[1][m] + (m-y)*(m-y))) ;
            early[x][y] = arr ;
         }
      }
   }
   ll lo = INF ;
   for (int i=0; i<(int)q[k-1].size(); i++)
      lo = min(lo, early[q[k-1][i].first][q[k-1][i].second]) ;
   if (lo == INF)
      cout << -1 << endl ;
   else
      cout << lo << endl ;
}
