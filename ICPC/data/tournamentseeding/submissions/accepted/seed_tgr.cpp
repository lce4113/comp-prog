#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;
int main() {
   int n, k ;
   cin >> n >> k ;
   int nn = 1LL<<n ;
   vector<int> r(nn) ;
   for (auto &v: r)
      cin >> v ;
   sort(r.rbegin(), r.rend()) ;
   int s = 0 ;
   for (int i=0; i<n; i++)
      for (int j=0, m=1LL<<i; (j>>i)==0; j++)
         if (r[j]-r[m]<=k)
            s++, m++ ;
   cout << s << endl ;
}
