#include <iostream>
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
int main() {
   cout << setprecision(15) ;
   cin >> n ;
   poly.resize(n) ;
   for (auto &v : poly)
      cin >> v.first >> v.second ;
   door = poly[0] ;
   pt p = poly[n-1] ;
   dt rarea = 0 ;
   for (auto v : poly) {
      rarea += ia(door, p) + ia(p, v) + ia(v, door) ;
      p = v ;
   }
   rarea *= 0.5 ;
   dt area = 0 ;
   p = poly[n-1] ;
   for (auto v : poly) {
      auto tarea = ia(door, p) + ia(p, v) + ia(v, door) ;
      if (area + tarea >= rarea) {
         pt lo = p ;
         pt d = {v.first-p.first, v.second-p.second} ;
         for (double f=0.5; f>1e-18; f *= 0.5) {
            pt t = { lo.first + f*d.first, lo.second + f*d.second } ;
            auto tarea = ia(door, p) + ia(p, t) + ia(t, door) ;
            if (area + tarea <= rarea)
               lo = t ;
         }
         cout << lo.first << " " << lo.second << endl ;
         return 0 ;
      }
      area += tarea ;
      p = v ;
   }
   cout << "Fell off end of world." << endl ;
}
