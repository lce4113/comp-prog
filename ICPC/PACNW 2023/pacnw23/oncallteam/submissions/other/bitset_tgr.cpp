#include <iostream>
#include <string>
#include <bitset>
using namespace std ;
const int MAXN = 30000, MAXM = 20 ;
using bs = bitset<MAXN> ;
bs dat[MAXM], st[MAXM+1] ;
int n, m, r ;
string s ;
void recur(int at, int bc, int t) {
   if (t < bc)
      r = min(t, r) ;
   for (; t<r && at<m; at++) {
      st[bc+1] = st[bc] | dat[at] ;
      recur(at+1, bc+1, st[bc+1].count()) ;
   }
}
int main() {
   cin >> n >> m ;
   for (int i=0; i<n; i++) {
      cin >> s ;
      for (int j=0; j<(int)s.size(); j++)
         dat[j][i] = s[j] - '0' ;
   }
   r = m ;
   recur(0, 0, 0) ;
   cout << r << endl ;
}
