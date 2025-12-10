#include <iostream>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std ;
using dt = double ;
using pt = pair<dt, dt> ;
using ll = long long ;
vector<pt> poly ;
pt door ;
int n ;
dt ia(pt &p, pt &v) {
   return (v.second + p.second) * (p.first - v.first) ;
}
dt tri(pt &a, pt &b, pt &c) {
   dt ab = hypot(a.second-b.second, a.first-b.first) ;
   dt bc = hypot(b.second-c.second, b.first-c.first) ;
   dt ac = hypot(a.second-c.second, a.first-c.first) ;
   dt p = (ab + bc + ac) * 0.5 ;
   return sqrt(p * (p - ab) * (p - bc) * (p - ac)) ;
}
int main() {
   cout << setprecision(15) ;
   cin >> n ;
   poly.resize(n) ;
   for (auto &v : poly)
      cin >> v.first >> v.second ;
   dt rarea = 0 ;
   door = poly[0] ;
   pt p = poly[n-1] ;
   for (auto v : poly) {
      rarea += tri(door, p, v) ;
      p = v ;
   }
   rarea *= 0.5 ;
   p = poly[n-1] ;
   dt area = 0 ;
   for (auto v : poly) {
      auto tarea = tri(door, p, v) ;
      if (area + tarea >= rarea) {
         pt d = {(p.first*(tarea+area-rarea)+v.first*(rarea-area))/tarea,
                 (p.second*(tarea+area-rarea)+v.second*(rarea-area))/tarea} ;
         cout << d.first << " " << d.second << endl ;
         return 0 ;
      }
      area += tarea ;
      p = v ;
   }
   cout << "Fell off end of world." << endl ;
}
