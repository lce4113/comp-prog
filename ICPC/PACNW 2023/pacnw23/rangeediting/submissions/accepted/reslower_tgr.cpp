/*
 *   This is the same as my other solution, except the order of the loops
 *   is different and this hurts both caching and vectorization, so the
 *   result is significantly slower.  But we likely want to accept it as it
 *   has the same complexity as my earlier solution.
 */
#include <iostream>
#include <vector>
using namespace std ;
const int MAX = 8000 ;
int n, a[MAX][MAX] ;
int main() {
   cin >> n ;
   vector<int> s(n) ;
   for (auto &v: s)
      cin >> v ;
   s.push_back(0) ;
   s.insert(s.begin(), 0) ;
   for (int len=2; len<=(int)s.size(); len++)
      for (int st=0; st+len<=(int)s.size(); st++)
         for (int sp=1; sp<len; sp++)
            a[len][st] = max(a[len][st], a[sp][st] + a[len-sp][st+sp] +
                             (s[st] == s[sp+st])) ;
   cout << s.size()-a[s.size()][0]-1 << endl ;
}
