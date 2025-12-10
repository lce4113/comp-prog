#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std ;
using ll = long long ;
const int MAXT = 2520 ;
const int MAXP = 51 ;
double dp[MAXT][MAXP] ;
int main() {
   int n, k, ct ;
   cin >> n >> k >> ct ;
   cout << setprecision(15) ;
   vector<double> p(n) ;
   vector<int> t(n) ;
   for (int i=0; i<n; i++)
      cin >> p[i] >> t[i] ;
   vector<double> sc(n) ;
   vector<pair<int, int>> sortme ;
   for (int r=0; r<n; r++)
      sortme.push_back({t[r], r}) ;
   sort(sortme.begin(), sortme.end()) ;
   dp[0][0] = 1 ;
   for (int i=0; i<(int)sortme.size(); i++) {
      int r = sortme[i].second ;
      for (int tt=ct-1; tt>=0; tt--) {
         for (int ai=min(k-1, i); ai>=0 && ai+(n-i) >= k; ai--) {
            if (dp[tt][ai] == 0)
               continue ;
            double pp = dp[tt][ai] ;
            double sp = (k - ai) / (double)(n - i) ;
            dp[tt][ai] = pp * (1 - sp) ;
            dp[tt][ai+1] += pp * sp * (1-p[r]) ;
            if (tt + t[r] <= ct) {
               dp[tt + t[r]][ai+1] += pp * sp * p[r] ;
               sc[r] += pp * sp * p[r] ;
            }
         }
      }
   }
   for (int i=0; i<n; i++)
      cout << sc[i] * n / k << endl ;
}
