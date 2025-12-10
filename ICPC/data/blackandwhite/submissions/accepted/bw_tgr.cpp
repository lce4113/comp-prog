#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std ;
using ll = long long ;
/*
 *   At round n, probability of moving on is
 *   n p (1-p) (p^{n-2} + (1-p)^{n-2}) so the expected number of rounds
 *   is 1 divided by that.
 */
int main() {
   cout << setprecision(15) ;
   int n ;
   cin >> n ;
   vector<double> p(n) ;
   for (auto &v: p)
      cin >> v ;
   ll pown = 1LL << n ;
   vector<double> pv(pown), res(pown) ;
   pv[0] = 1 ;
   vector<double> w(n) ;
   for (ll mask=0; (mask>>n)==0; mask++) {
      double ep = 0 ;
      for (int b=0; b<n; b++) {
         if ((mask >> b) & 1)
            continue ;
         double p1=1, p2=1 ;
         for (int i=0; i<n; i++) {
            if ((mask >> i) & 1)
               continue ;
            if (i == b) {
               p1 *= p[i] ;
               p2 *= 1-p[i] ;
            } else {
               p2 *= p[i] ;
               p1 *= 1-p[i] ;
            }
         }
         w[b] = p1 + p2 ;
         ep += w[b] ;
      }
      res[mask] = 1 / ep ;
      for (int b=0; b<n; b++) {
         if ((mask >> b) & 1)
            continue ;
         ll dst = mask | (1LL << b) ;
         pv[dst] += pv[mask] * w[b] / ep ;
      }
   }
   double s = 0 ;
   for (ll mask=0; (mask>>n)==0; mask++) {
      if (__builtin_popcount(mask) + 2 >= n)
         continue ;
      s += pv[mask] * res[mask] ;
   }
   cout << s << endl ;
}
