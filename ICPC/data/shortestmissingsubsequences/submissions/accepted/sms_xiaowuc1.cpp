#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  vector<int> remap(256, -1);
  vector<vector<int>> locs;
  {
    string s;
    cin >> s;
    locs.resize(s.size());
    for(int i = 0; i < s.size(); i++) remap[s[i]] = i;
  }
  vector<int> v;
  {
    string s;
    cin >> s;
    v.resize(s.size());
    for(int i = 0; i < v.size(); i++) locs[v[i] = remap[s[i]]].push_back(i);
  }
  int wantlen = 1;
  {
    int lhs = -1;
    while(true) {
      int biggest = lhs;
      for(int i = 0; i < locs.size(); i++) {
        if(locs[i].size() == 0 || locs[i].back() <= lhs) biggest = 2e9;
        else biggest = max(biggest, *upper_bound(locs[i].begin(), locs[i].end(), lhs));
      }
      if(biggest == 2e9) break;
      wantlen++;
      lhs = biggest;
    }
  }
  int q;
  cin >> q;
  while(q--) {
    string s;
    cin >> s;
    string ret = "1";
    if(s.size() != wantlen) ret = "0";
    else {
      int lhs = -1;
      for(int i = 0; lhs < 2e9 && i < s.size(); i++) {
        int idx = remap[s[i]];
        auto it = upper_bound(locs[idx].begin(), locs[idx].end(), lhs);
        if(it == locs[idx].end()) lhs = 2e9;
        else lhs = *it;
      }
      if(lhs != 2e9) ret = "0";
    }
    cout << ret << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  solve();
}
