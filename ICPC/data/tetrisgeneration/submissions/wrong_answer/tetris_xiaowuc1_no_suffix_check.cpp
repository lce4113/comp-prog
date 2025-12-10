#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    int ret = 0;
    for(int skip = 0; ret == 0 && skip <= (int)s.size() && skip < 7; skip++) {
      string p = s.substr(s.size() - skip);
      if(false) {
        set<char> s(p.begin(), p.end());
        if(p.size() != s.size()) break;
      }
      string curr = s.substr(0, s.size() - skip);
      bool good = true;
      while(curr.size() && good) {
        string prefix = curr.substr(0, min(7, (int)curr.size()));
        curr = curr.substr((int)prefix.size());
        set<char> ss(prefix.begin(), prefix.end());
        if(ss.size() != prefix.size()) good = false;
      }
      if(good) ret = 1;
    }
    cout << ret << "\n";
  }
}