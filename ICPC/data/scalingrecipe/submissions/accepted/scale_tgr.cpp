#include <iostream>
using namespace std ;
int main() {
   int n, x, y ;
   cin >> n >> x >> y ;
   for (int i=0; i<n; i++) {
      int a ;
      cin >> a ;
      int b = a * y / x ;
      cout << b << endl ;
   }
}
