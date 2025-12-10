#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std ;
struct ptlin {
   double x, y, xmin, xmax ;
} ;
int main() {
   int n ;
   cout << setprecision(15) ;
   cin >> n ;
   vector<ptlin> a(n) ;
   for (auto &p: a)
      cin >> p.x >> p.y >> p.xmin >> p.xmax ;
   for (int mir=0; mir<2; mir++) {
      vector<ptlin> s ;
      for (auto &p: a) {
         while (s.size() > 0) {
            auto &p2 = s[s.size()-1] ;
            if (p2.y > p.y)
               break ;
            s.pop_back() ;
            if (p2.y < p.y)
               p.xmin = max(p.xmin, p.x + (p2.x - p.x) * p.y / (p.y - p2.y)) ;
            else if (p.x < p2.x)
               p.xmin = p.xmax + 1 ;
         }
         s.push_back(p) ;
         p = {-p.x, p.y, -p.xmax, -p.xmin} ;
      }
      reverse(a.begin(), a.end()) ;
   }
   double s = 0 ;
   for (auto p: a) {
      if (p.xmax < p.xmin) {
         cout << -1 << endl ;
         exit(0) ;
      }
      if (p.xmin <= p.x && p.x <= p.xmax)
         s += p.y ;
      else
         s += min(hypot(p.y, p.x-p.xmin), hypot(p.y, p.x-p.xmax)) ;
   }
   cout << s << endl ;
}
