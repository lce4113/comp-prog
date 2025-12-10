#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int ret = 0;
    string s;
    cin >> s;
    for(int skip = 0; ret == 0 && skip <= (int)s.size() && skip < 7; skip++) {
      string p = s.substr(0, skip);
      if(false) {
        set<char> s(p.begin(), p.end());
        if(p.size() != s.size()) break;
      }
      string curr = s.substr(skip);
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