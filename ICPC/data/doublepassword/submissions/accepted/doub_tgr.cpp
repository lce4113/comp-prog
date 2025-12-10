#include <iostream>
#include <string>
using namespace std ;
int main() {
   string a, b ;
   cin >> a >> b ;
   int r = 1 ;
   for (int i=0; i<(int)a.size(); i++)
      r <<= (a[i] != b[i]) ;
   cout << r << endl ;
}
