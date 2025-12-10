#include <iostream>
#include <vector>
using namespace std ;
const int MAX = 100 ;
int R, C ;
struct perm {
   int b[MAX][MAX], r[MAX*MAX], c[MAX*MAX] ;
   void readperm() {
      for (int i=0; i<R; i++)
         for (int j=0; j<C; j++) {
            cin >> b[i][j] ;
            r[b[i][j]] = i ;
            c[b[i][j]] = j ;
         }
   }
} src, dst ;
struct sw {
   int r1, c1, r2, c2 ;
} ;
int main() {
   cin >> R >> C ;
   src.readperm() ;
   dst.readperm() ;
   vector<sw> swaps ;
   for (int i=1; i<=R*C; i++)
      while (src.r[i] != dst.r[i] || src.c[i] != dst.c[i]) {
         int cc = src.c[i] ;
         while (cc+1 < C && src.b[src.r[i]][cc+1] < src.b[dst.r[i]][dst.c[i]])
            cc++ ;
         swaps.push_back({1+dst.r[i], 1+dst.c[i], 1+src.r[i], 1+cc}) ;
         int j = src.b[dst.r[i]][dst.c[i]] ;
         int k = src.b[src.r[i]][cc] ;
         swap(src.b[dst.r[i]][dst.c[i]], src.b[src.r[i]][cc]) ;
         swap(src.r[k], src.r[j]) ;
         swap(src.c[k], src.c[j]) ;
      }
   cout << swaps.size() << endl ;
   for (auto sw: swaps)
      cout << sw.r1 << " " << sw.c1 << " " << sw.r2 << " " << sw.c2 << endl ;
}
