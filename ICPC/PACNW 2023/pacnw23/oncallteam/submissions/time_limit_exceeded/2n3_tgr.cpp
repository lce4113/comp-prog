#include <iostream>
#include <string>
using namespace std ;
const int MAX = 1<<20 ;
int n, m, a[MAX], f[MAX] ;
string s ;
int main() {
   cin >> n >> m ;
   for (int i=0; i<n; i++) {
      cin >> s ;
      int b = 0 ;
      for (int j=0; j<(int)s.size(); j++)
         b |= (s[j] - '0') << j ;
      a[b]++ ;
   }
   int r = m ;
   for (int i=1; i<(1<<m); i++) {
      int lobit = i & - i ;
      int cnt = f[i-lobit] + a[lobit] ;
      int noti = ((1<<m)-1-i);
      for (int j=noti; j>0; j=(j-1)&noti)
         cnt += a[j|lobit] ;
      f[i] = cnt ;
      if (cnt < __builtin_popcount(i) && cnt < r)
         r = cnt ;
   }
   cout << r << endl ;
}
