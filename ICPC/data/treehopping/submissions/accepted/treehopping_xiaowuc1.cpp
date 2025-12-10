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
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<vector<int>> edges(n);
    vector<int> depth(n);
    vector<int> par(n, -1);
    for(int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      edges[--a].push_back(--b);
      edges[b].push_back(a);
    }
    auto dfs = y_combinator([&](auto self, int curr) -> void {
      for(int out: edges[curr]) {
        if(out == par[curr]) continue;
        par[out] = curr;
        depth[out] = depth[curr] + 1;
        self(out);
      }
    }); dfs(0);
    auto is_valid = [&](int a, int b) -> bool {
      if(abs(depth[a] - depth[b]) > 3) return false;
      int d = 0;
      while(a != b) {
        if(++d > 3) return false;
        if(depth[a] >= depth[b]) a = par[a];
        else b = par[b];
      }
      return true;
    };
    vector<int> v(n);
    for(auto& x: v) {
      cin >> x;
      x--;
    }
    int ret = 1;
    for(int i = 1; ret && i < n; i++) if(!is_valid(v[i-1], v[i])) ret = 0;
    cout << ret << "\n";
  }
}