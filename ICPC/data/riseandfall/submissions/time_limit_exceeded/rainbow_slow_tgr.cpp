#include <iostream>
using namespace std ;
using ll = long long ;
int israinbow(ll v) {
   int p = 0 ;
   while (v && (v % 10) >= p) {
      p = v % 10 ;
      v /= 10 ;
   }
   while (v && (v % 10) <= p) {
      p = v % 10 ;
      v /= 10 ;
   }
   return (v == 0) ;
}
int main() {
   int t;
   cin >> t;
   while(t--) {
      ll v ;
      cin >> v ;
      while (!israinbow(v))
         v-- ;
      cout << v << endl ;
   }
}
