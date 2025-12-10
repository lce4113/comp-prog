#include <iostream>
#include <string>
using namespace std ;
int main() {
   int t;
   cin >> t;
   while(t--) {
      string in ;
      cin >> in ;
      int i = 0 ;
      while (i + 1 < (int)in.size() && in[i] <= in[i+1])
         i++ ;
      while (i + 1 < (int)in.size() && in[i] >= in[i+1])
         i++ ;
      for (; (i+1) < (int)in.size(); i++)
         in[i+1] = in[i] ;
      cout << in << endl ;
   }
}
