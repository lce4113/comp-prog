#include <iostream>
using namespace std ;
using ll = long long ;
int main() {
   ll t, a, b, n, k ;
   cin >> t ;
   while (t--) {
      ll r = 0 ;
      cin >> n >> k >> a >> b ;
      b -= a ;
      ll aat = 1 ;
      if (n * b >= a) {
         while (k) {
            aat *= 2 ;
            ll y = n * b / a ;
            while (aat > 1 && (y * aat > k || (n + y * aat) * b / a > y))
               aat >>= 1 ;
            if (y > k)
               y = k ;
            n += aat * y ;
            k -= aat * y ;
            r += aat ;
         }
      } else
         r = -1 ;
      cout << r << endl ;
   }
}
