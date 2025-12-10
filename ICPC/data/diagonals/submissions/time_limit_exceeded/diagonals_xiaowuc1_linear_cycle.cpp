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
  vector<vector<vector<pair<int, int>>>> edges(n+1);
  for(auto& x: edges) x.resize(n+1);
  vector<vector<int>> seen(n+1);
  for(auto& x: seen) x.resize(n+1);
  auto has_cycle = [&]() -> bool {
    auto dfs = y_combinator([&](auto self, int x, int y, int px, int py) -> bool {
      assert(seen[x][y] == 0);
      seen[x][y] = 1;
      for(auto [nx, ny]: edges[x][y]) {
        if(nx == px && ny == py) continue;
        if(seen[nx][ny] == 1) return true;
        if(seen[nx][ny] == 0) if(self(nx, ny, x, y)) return true;
      }
      seen[x][y] = 2;
      return false;
    });
    for(auto& out: seen) fill(out.begin(), out.end(), 0);
    for(int i = 0; i < n+1; i++) {
      for(int j = 0; j < n+1; j++) {
        if(seen[i][j] == 0) if(dfs(i, j, -1, -1)) return true;
      }
    }
    return false;
  };
  auto dfs = y_combinator([&](auto self, int x, int y) -> bool {
    if(has_cycle()) return false;
    if(x == n) {
      for(auto out: g) for(auto out2: out) if(out2 > 0) return false; return true;
    }
    if(y == n) return self(x+1, 0);
    if(g[x][y] > 1) return false;
    if(g[x][y] == 1) {
      if(g[x+1][y+1] == 0) return false;
      ret[x][y] = '\\';
      g[x][y]--;
      g[x+1][y+1]--;
      edges[x][y].emplace_back(x+1, y+1);
      edges[x+1][y+1].emplace_back(x, y);
      if(self(x, y+1)) return true;
      g[x][y]++;
      g[x+1][y+1]++;
      edges[x][y].pop_back();
      edges[x+1][y+1].pop_back();
      return false;
    }
    if(g[x][y] != 0 && g[x+1][y+1] != 0) {
      ret[x][y] = '\\';
      g[x][y]--;
      g[x+1][y+1]--;
      edges[x][y].emplace_back(x+1, y+1);
      edges[x+1][y+1].emplace_back(x, y);
      if(self(x, y+1)) return true;
      g[x][y]++;
      g[x+1][y+1]++;
      edges[x][y].pop_back();
      edges[x+1][y+1].pop_back();
    }
    if(g[x][y+1] != 0 && g[x+1][y] != 0) {
      ret[x][y] = '/';
      g[x][y+1]--;
      g[x+1][y]--;
      edges[x][y+1].emplace_back(x+1, y);
      edges[x+1][y].emplace_back(x, y+1);
      if(self(x, y+1)) return true;
      g[x][y+1]++;
      g[x+1][y]++;
      edges[x][y+1].pop_back();
      edges[x+1][y].pop_back();
    }
    return false;
  }); assert(dfs(0, 0));
  for(int i = 0; i < n; i++) {
    for(auto out: ret[i]) cout << out; cout << "\n";
  }
}