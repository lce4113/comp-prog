#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std ;
using ll = long long ;
int main() {
   int n, k, ct ;
   cin >> n >> k >> ct ;
   cout << setprecision(15) ;
   vector<double> p(n) ;
   vector<int> t(n) ;
   for (int i=0; i<n; i++)
      cin >> p[i] >> t[i] ;
   vector<double> sc(n) ;
   vector<ll> pc(n) ;
   vector<char> sel(n) ;
   for (int i=n-k; i<n; i++)
      sel[i] = 1 ;
   int permc = 0 ;
   do {
      permc++ ;
      vector<pair<int, int>> sortme ;
      for (int r=0; r<n; r++)
         if (sel[r]) {
            pc[r]++ ;
            sortme.push_back({t[r], r}) ;
         }
      sort(sortme.begin(), sortme.end()) ;
      vector<double> tp(ct+1) ;
      tp[0] = 1 ;
      for (int i=0; i<(int)sortme.size(); i++) {
         int r = sortme[i].second ;
         for (int tt=ct-1; tt>=0; tt--) {
            if (tp[tt] == 0)
               continue ;
            double pp = tp[tt] ;
            tp[tt] = pp * (1-p[r]) ;
            if (tt + t[r] <= ct) {
               tp[tt + t[r]] += pp * p[r] ;
               sc[r] += pp * p[r] ;
            }
         }
      }
   } while (next_permutation(sel.begin(), sel.end())) ;
   for (int i=0; i<n; i++)
      cout << sc[i] / pc[i] << endl ;
}
