#include <iostream>
#include <vector>
#include <string>
using namespace std ;
vector<vector<int>> adj ;
vector<char> stack ;
string lab ;
int a, b, n, s ;
int recur(int at, int p) {
   int r = 0 ;
   int restore = -1 ;
   if (lab[at] == '(' || lab[at] == '{' || lab[at] == '[') {
      stack.push_back(lab[at]) ;
   } else {
      if (stack.size() == 0 || (stack[stack.size()-1] ^ lab[at]) >= 16)
         return r ;
      restore = stack[stack.size()-1] ;
      stack.pop_back() ;
   }
   if (stack.size() == 0 && p >= 0)
      r++ ;
   for (auto v: adj[at])
      if (v != p)
         r += recur(v, at) ;
   if (restore < 0)
      stack.pop_back() ;
   else
      stack.push_back(restore) ;
   return r ;
}
int main(int argc, char *argv[]) {
   cin >> n >> lab ;
   adj.resize(n) ;
   for (int i=0; i+1<n; i++) {
      cin >> a >> b ;
      a-- ; b-- ;
      adj[a].push_back(b) ;
      adj[b].push_back(a) ;
   }
   for (int i=0; i<n; i++)
      s += recur(i, -1) ;
   cout << s << endl ;
}
