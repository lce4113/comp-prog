#include <iostream>
#include <string>
using namespace std ;
const int MAXN = 30000 ;
int n, m, a[MAXN] ;
string s ;
int kernel(int bm) {
   int r = 0 ;
   for (int i=0; i<n; i++)
      if (bm & a[i])
         r++ ;
   return r ;
}
int main() {
   cin >> n >> m ;
   for (int i=0; i<n; i++) {
      cin >> s ;
      for (int j=0; j<(int)s.size(); j++)
         a[i] |= (s[j] - '0') << j ;
   }
   int r = m ;
   for (int i=1; i<(1<<m); i++) {
      int t = kernel(i) ;
      if (t < __builtin_popcount(i) && t < r)
         r = t ;
   }
   cout << r << endl ;
}
