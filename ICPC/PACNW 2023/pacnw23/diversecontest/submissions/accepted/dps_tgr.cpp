#include <iostream>
#include <map>
using namespace std ;
const int MAX = 20 ;
int topics[MAX][MAX] ;
int cnts[MAX*MAX], n, k, r, tc[MAX] ;
map<string, int> topmap ;
string top ;
int topn ;
int lookup(string s) {
   if (topmap.find(s) == topmap.end())
      topmap[s] = topn++ ;
   return topmap[s] ;
}
void recur(int at, int sofar) {
   if (sofar == k) {
      r++ ;
      return ;
   }
   if (at == n)
      return ;
   recur(at+1, sofar) ;
   int ok = 1 ;
   for (int i=0; i<tc[at]; i++) {
      cnts[topics[at][i]]++ ;
      if (cnts[topics[at][i]] * 2 > k)
         ok = 0 ;
   }
   if (ok)
      recur(at+1, sofar+1) ;
   for (int i=0; i<tc[at]; i++)
      cnts[topics[at][i]]-- ;
}
int main() {
   cin >> n >> k ;
   for (int i=0; i<n; i++) {
      cin >> tc[i] ;
      for (int j=0; j<tc[i]; j++) {
         cin >> top ;
         topics[i][j] = lookup(top) ;
      }
   }
   recur(0, 0) ;
   cout << r << endl ;
}
