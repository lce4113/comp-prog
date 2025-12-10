#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

bool issorted(const vector<int>& v) {
  for(int i = 1; i < v.size(); i++) if(v[i] < v[i-1]) return false;
  return true;
}

vector<array<int, 4>> solve(vector<vector<int>>& g) {
  vector<array<int, 4>> ret;
  int r = g.size();
  int c = g[0].size();
  vector<array<int, 2>> ord;
  for(int j = 0; j < c; j++) for(int i = 0; i < r; i++) ord.push_back({i, j});
  while(true) {
    bool done = true;
    for(int i = 0; done && i < r; i++) for(int j = 0; done && j < c; j++) done = g[i][j] == j*r+i;
    if(done) break;
    bool found = false;
    for(int aidx = 0; !found && aidx < ord.size(); aidx++) for(int bidx = aidx+1; !found && bidx < ord.size(); bidx++) {
      auto [a, x] = ord[aidx];
      auto [b, y] = ord[bidx];
      if(g[a][x] < g[b][y]) continue;
      swap(g[a][x], g[b][y]);
      if(issorted(g[a]) && issorted(g[b])) {
        found = true;
        ret.push_back({a+1, x+1, b+1, y+1});
      }
      else swap(g[a][x], g[b][y]);
    }
    assert(found);
  }
  return ret;
}

int main() {
  int r, c;
  cin >> r >> c;
  vector<vector<int>> a(r), b(r);
  for(auto& x: a) {
    x.resize(c);
    for(auto& y: x) {
      cin >> y;
      y--;
    }
  }
  for(auto& x: b) {
    x.resize(c);
    for(auto& y: x) {
      cin >> y;
      y--;
    }
  }
  vector<array<int, 4>> amove = solve(a);
  vector<array<int, 4>> bmove = solve(b);
  reverse(bmove.begin(), bmove.end());
  cout << (amove.size() + bmove.size()) << "\n";
  for(auto [p, q, r, s]: amove) cout << p << " " << q << " " << r << " " << s << "\n";
  for(auto [p, q, r, s]: bmove) cout << p << " " << q << " " << r << " " << s << "\n";
}
