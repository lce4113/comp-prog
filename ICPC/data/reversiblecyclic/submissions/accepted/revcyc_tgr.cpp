#include <algorithm>
#include <iostream>
#include <string>
using namespace std ;
int main() {
   string s ;
   cin >> s ;
   string ss = s + s ;
   reverse(ss.begin(), ss.end()) ;
   cout << (ss.find(s) != string::npos) << endl ;
}
