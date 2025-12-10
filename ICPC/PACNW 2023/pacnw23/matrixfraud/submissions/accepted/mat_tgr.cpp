#include <iostream>
#include <vector>
#include <string>
using namespace std ;
const int MAXC = 1000 ;
char a[MAXC*MAXC] ;
int r, c, sum[MAXC], dp[2][MAXC][MAXC], minx[MAXC][MAXC] ;
string s ;
int main() {
   cin >> r >> c ;
   for (int i=0; i<r; i++) {
      cin >> s ;
      for (int j=0; j<c; j++)
         if (r >= c)
            a[j+c*i] = s[j] - '0' ;
         else
            a[i+r*j] = s[j] - '0' ;
   }
   if (r < c)
      swap(r, c) ;
   int rd=0, wr=1 ;
   for (int i=0; i<r; i++) {
      int s = 0 ;
      for (int j=0; j<c; j++) {
         s += a[i*c+j] ;
         sum[j+1] = s ;
      }
      for (int y1=0; y1<=c; y1++) {
         int mv = r*c ;
         for (int x1=0; x1<=y1; x1++) {
            minx[x1][y1] = mv ;
            mv = min(mv, dp[rd][x1][y1]) ;
         }
      }
      for (int x2=0; x2<c; x2++) {
         int mv = minx[x2][x2] ;
         for (int y2=x2+1; y2<=c; y2++) {
            mv = min(mv, minx[x2+1][y2]) ;
            dp[wr][x2][y2] = sum[x2] + (y2 - x2 - (sum[y2]-sum[x2])) +
                           (s - sum[y2]) + (i == 0 ? x2 == 0 ? 0 : r*c : mv) ;
         }
      }
      swap(rd, wr) ;
   }
   int rv = r * c ;
   for (int x2=0; x2<c; x2++)
      rv = min(rv, dp[rd][x2][c]) ;
   cout << rv << endl ;
}
