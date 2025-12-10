#include <iostream>
#include <string>
#include <vector>
using namespace std ;
const int MAX = 256 ;
int N, K ;
char res[MAX] ;
vector<string> gradees ;
vector<int> mods ;
int chase(int at, int val) {
   if (res[at])
      return res[at] == val ;
   res[at] = val ;
   mods.push_back(at) ;
   for (int i=0; i<N; i++)
      if (gradees[i][at] == val)
         for (int j=0; j<K; j++)
            if (j != at && gradees[i][j] != 'X') {
               if (!chase(j, 'T'+'F'-gradees[i][j]))
                  return 0 ;
            }
   return 1 ;
}
void unchase(int sp) {
   while ((int)mods.size() > sp) {
      res[mods[mods.size()-1]] = 0 ;
      mods.pop_back() ;
   }
}
int recur(int at) {
   if (at == K)
      return 1 ;
   for (int i=0; i<2; i++) {
      int sp = mods.size() ;
      if (chase(at, "FT"[i]) && recur(at+1))
         return 1 ;
      unchase(sp) ;
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
