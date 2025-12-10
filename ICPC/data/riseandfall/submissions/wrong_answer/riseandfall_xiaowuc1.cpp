#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    bool drop = false;
    char lhs = '0';
    for(int i = 0; i < (int)s.size(); i++) {
      if(drop) cout << (lhs = min(s[i], lhs));
      else {
        cout << s[i];
        drop = s[i] < lhs;
        lhs = s[i];
      }
    }
    cout << "\n";
  }
}