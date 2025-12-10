#include <cassert>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

template<class Fun>
class y_combinator_result {
  Fun fun_;
public:
  template<class T>
  explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

  template<class ...Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

struct disjoint_set {
  vector<int> p, sz;
  vector<pair<int, int>> pv, szv;
  disjoint_set(int n) {
    p.resize(n); fill(p.begin(), p.end(), -1);
    sz.resize(n); fill(sz.begin(), sz.end(), 1);
  }
  int find(int x) {
    while(p[x] != -1) x = p[x];
    return x;
  }
  int getsz(int x) {
    return sz[find(x)];
  }
  bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return false;
    if(sz[x] < sz[y]) swap(x, y);
    pv.emplace_back(y, p[y]);
    szv.emplace_back(x, sz[x]);
    p[y] = x;
    sz[x] += sz[y];
    return true;
  }
  void revert() {
    p[pv.back().first] = pv.back().second;
    sz[szv.back().first] = szv.back().second;
    pv.pop_back();
    szv.pop_back();
  }
};

int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n+1);
  for(auto& x: g) {
    string s;
    cin >> s;
    x.resize(n+1);
    for(int j = 0; j < n+1; j++) {
      if(s[j] == '+') x[j] = -1;
      else x[j] = s[j] - '0';
    }
  }
  vector<vector<char>> ret(n);
  for(auto& x: ret) x.resize(n);
  disjoint_set dsu(g.size() * g.size());
  auto dfs = y_combinator([&](auto self, int x, int y) -> void {
    if(x == n) {
      for(auto out: g) for(auto out2: out) if(out2 > 0) return;
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << ret[i][j];
        cout << "\n";
      }
      return;
    }
    if(y == n) return self(x+1, 0);
    if(g[x][y] > 1) return;
    if(g[x][y] == 1) {
      if(g[x+1][y+1] == 0) return;
      if(!dsu.merge(x*(n+1)+y, (x+1)*(n+1)+y+1)) return;
      ret[x][y] = '\\';
      g[x][y]--;
      g[x+1][y+1]--;
      self(x, y+1);
      g[x][y]++;
      g[x+1][y+1]++;
      dsu.revert();
      return;
    }
    if(g[x][y] != 0 && g[x+1][y+1] != 0 && dsu.merge(x*(n+1)+y, (x+1)*(n+1)+y+1)) {
      ret[x][y] = '\\';
      g[x][y]--;
      g[x+1][y+1]--;
      self(x, y+1);
      g[x][y]++;
      g[x+1][y+1]++;
      dsu.revert();
    }
    if(g[x][y+1] != 0 && g[x+1][y] != 0 && dsu.merge(x*(n+1)+y+1, (x+1)*(n+1)+y)) {
      ret[x][y] = '/';
      g[x][y+1]--;
      g[x+1][y]--;
      self(x, y+1);
      g[x][y+1]++;
      g[x+1][y]++;
      dsu.revert();
    }
  }); 
  dfs(0, 0);
}