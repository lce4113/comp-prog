#include <iostream>
#include <string>
using namespace std ;
void doit() {
   string s ;
   cin >> s ;
   int good = 0 ;
   for (int a=0; a<7 && a<(int)s.size(); a++) {
      int bits = 0 ;
      int nogood = 0 ;
      for (int i=0; i<(int)s.size(); i++) {
         if ((bits >> (s[i]-'A')) & 1)
            nogood++ ;
         bits |= 1<<(s[i]-'A') ;
         if ((i - a) % 7 == 0)
            bits = 0 ;
      }
      if (!nogood) {
// cout << "Good at " << a << endl ;
         good = 1 ;
      }
   }
   cout << good << endl ;
}
int main() {
   int n ;
   cin >> n ;
   while (n--) {
      doit() ;
   }
}
