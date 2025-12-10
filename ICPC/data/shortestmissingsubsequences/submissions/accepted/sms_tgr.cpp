#include <iostream>
#include <vector>
#include <string>
using namespace std ;
int main(int argc, char *argv[]) {
   int verbose = (argc > 1) ;
   string alpha ;
   string remap ;
   cin >> alpha ;
   remap.resize(256) ;
   for (int i=0; i<(int)alpha.size(); i++)
      remap[alpha[i]-'a'] = 'a' + i ;
   int an = alpha.size() ;
   string hay ;
   cin >> hay ;
   for (int i=0; i<(int)hay.size(); i++)
      hay[i] = remap[hay[i]-'a'] ;
   int n = hay.size() ;
   vector<int> fwd(n * an, n+10) ; // forward pointers
   fwd[(n-1)*an+hay[n-1]-'a'] = n-1 ;
   vector<int> shrt(n+1) ;
   for (int i=n-2; i>=0; i--) {
      for (int j=0; j<an; j++)
         fwd[i*an+j] = fwd[i*an+j+an] ;
      fwd[i*an+hay[i]-'a'] = i ;
   }
   for (int i=n-1; i>=0; i--) {
      int s = n + 10 ;
      for (int j=0; j<an; j++) {
         if (fwd[i*an+j] == n + 10)
            s = 0 ;
         else
            s = min(s, 1+shrt[1+fwd[i*an+j]]) ;
      }
      shrt[i] = s ;
   }
   int t ;
   cin >> t ;
   for (int trial=0; trial<t; trial++) {
      string s ;
      cin >> s ;
      int missing = 0 ;
      if ((int)s.size() == 1 + shrt[0]) {
         int pos = 0 ;
         for (int i=0; i<(int)s.size(); i++) {
            if (pos >= n)
               pos++ ;
            else {
               int c = remap[s[i]-'a'] ;
               pos = fwd[pos*an+c-'a'] + 1 ;
            }
         }
         if (pos > n)
            missing = 1 ;
      }
      if (missing)
         cout << "1" << endl ;
      else
         cout << "0" << endl ;
   }
}
