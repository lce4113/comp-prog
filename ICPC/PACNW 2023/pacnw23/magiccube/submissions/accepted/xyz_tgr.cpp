#include <iostream>
#include <vector>
using namespace std ;
struct cmd {
   char op ;
   int deg, lev ;
} cur ;
vector<cmd> twists ;
struct pt {
   int x, y, z ;
} pos ;
int n, m ;
int main() {
   cin >> n >> m ;
   while (cin >> cur.op >> cur.deg >> cur.lev) {
      if (cur.op != 'q')
         twists.push_back(cur) ;
      else {
         pos = {cur.deg, cur.lev, 0} ;
         cin >> pos.z ;
         for (auto tw = twists.rbegin(); tw != twists.rend(); tw++) {
            for (int deg=tw->deg; deg > 0; deg -= 90) {
               switch (tw->op) {
case 'x':         if (pos.x > tw->lev) pos = {pos.x, n+1-pos.z, pos.y} ; break ;
case 'y':         if (pos.y > tw->lev) pos = {pos.z, pos.y, n+1-pos.x} ; break ;
case 'z':         if (pos.z > tw->lev) pos = {n+1-pos.y, pos.x, pos.z} ; break ;
               }
            }
         }
         cout << pos.x + n * (pos.y - 1 + n * (pos.z - 1)) << endl ;
      }
   }
}
