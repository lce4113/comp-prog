#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
using namespace std ;
using ll = long long ;
int n ;
vector<double> pi ;
vector<int> sn ;
const int MAX = 256 ;
double a[MAX][MAX], b[MAX][MAX] ;
vector<double> stationary(int n, double p) {
   for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
         if (j == 0 || j == n-1) {
            a[i][j] = (i == j ? 1 : 0) ;
         } else if (j == i + 1)
            a[i][j] = 1-p ;
         else if (i == j + 1)
            a[i][j] = p ;
         else
            a[i][j] = 0 ;
   int delta = 2 ;
   while (1) {
      for (int i=0; i<n; i++)
         for (int j=0; j<n; j++) {
            double s = 0 ;
            if (i == 0 || i == n-1 || i==j || abs(i-j) == delta)
               for (int k=0; k<n; k++)
                  s += a[i][k] * a[k][j] ;
            b[i][j] = s ;
         }
      delta *= 2 ;
      for (int i=0; i<n; i++)
         for (int j=0; j<n; j++)
            a[i][j] = b[i][j] ;
      for (int i=0; i<n; i++)
         for (int j=0; j<n; j++)
            b[i][j] = 0 ;
      // reallocate identity values
      for (int i=1; i+1<n; i++) {
         double iv = 1/(1-a[i][i]) ;
         for (int j=0; j<n; j++)
            a[j][i] *= iv ;
         a[i][i] = 0 ;
      }
      double lft = 0 ;
      for (int i=1; i+1<n; i++)
         for (int j=0; j<n; j++)
            lft += a[i][j] ;
      if (lft < 1e-15)
         break ;
   }
   vector<double> r(n) ;
   for (int i=0; i<n; i++)
      r[i] = a[n-1][i] ;
   return r ;
}
int main() {
   cin >> n ;
   cout << setprecision(15) ;
   pi.resize(n) ;
   sn.resize(n) ;
   for (auto &v: pi)
      cin >> v ;
   for (auto &v: sn)
      cin >> v ;
   vector<vector<vector<double>>> steps(n) ;
   for (int i=0; i<n; i++) {
      steps[i].resize(n) ;
      for (int j=0; j<n; j++)
         steps[i][j] = stationary(2*sn[j]+1, pi[i]) ;
   }
   vector<double> hi(1LL<<n) ;
   hi[0] = 1 ;
   for (ll mask=0; (mask>>n)==0; mask++) {
      double hip = hi[mask] ;
      int stage = __builtin_popcount(mask) ;
      int los = sn[stage] ;
      int his = sn[stage] ;
      if (stage > 0) {
         los -= sn[stage-1] ;
         his += sn[stage-1] ;
      }
      for (ll b=0; b<n; b++)
         if (((mask >> b) & 1) == 0) {
            double p = hip * steps[b][stage][his] +
                       (1-hip) * steps[b][stage][los] ;
            hi[mask | (1LL << b)] = max(hi[mask | (1LL << b)], p) ;
         }
   }
   cout << hi[(1LL << n) - 1] << endl ;
}
