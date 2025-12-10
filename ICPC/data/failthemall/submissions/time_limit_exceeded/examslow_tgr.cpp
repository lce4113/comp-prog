#include <iostream>
#include <string>
#include <vector>
using namespace std ;
const int MAX = 256 ;
int N, K ;
char res[MAX] ;
int agree[MAX] ;
vector<string> gradees ;
int recur(int at) {
   if (at == K)
      return 1 ;
   for (int i=0; i<2; i++) {
      res[at] = "FT"[i] ;
      int ok = 1 ;
      for (int j=0; j<N; j++)
         if (gradees[j][at] == "FT"[i] && agree[j]++ >= 1)
            ok = 0 ;
      if (ok && recur(at+1))
         return 1 ;
      for (int j=0; j<N; j++)
         if (gradees[j][at] == "FT"[i])
            agree[j]-- ;
   }
   return 0 ;
}
int main() {
   cin >> N >> K ;
   gradees.resize(N) ;
   for (auto &s: gradees)
      cin >> s ;
   int sol = recur(0) ;
   if (sol)
      for (int i=0; i<K; i++)
         cout << res[i] ;
   else
      cout << -1 ;
   cout << endl ;
}
