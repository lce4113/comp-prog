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
    bool tight = true;
    for(int i = 0; i < (int)s.size(); i++) {
      if(drop) {
        if(tight) {
          cout << min(s[i], lhs);
          tight = s[i] <= lhs;
          lhs = min(s[i], lhs);
        }
        else cout << lhs;
      }
      else {
        cout << s[i];
        drop = s[i] < lhs;
        lhs = s[i];
      }
    }
    cout << "\n";
  }
}