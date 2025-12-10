#include <iostream>
#include <vector>
using namespace std ;
int main() {
   int w, h, d, n ;
   cin >> w >> h >> d >> n ;
   vector<pair<int, int>> c(n) ;
   for (auto &cc: c) cin >> cc.first >> cc.second ;
   int ret = n ;
   for (int x=1; x<=w; x++)
      for (int y=1; y<=h; y++) {
         int r = 0 ;
         for (auto cc: c)
            if ((x-cc.first)*(x-cc.first)+(y-cc.second)*(y-cc.second)<=d*d) {
               r++ ;
               if (x == cc.first && y == cc.second)
                  r += 1000000 ;
            }
         ret = min(r, ret) ;
      }
   cout << ret << endl ;
}
