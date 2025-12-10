#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for(auto& x: v) cin >> x;
  vector<int> ret;
  for(int k = 2; k <= n; k++) {
    int sz = n/k;
    vector<int> lv(n+1, 1e9);
    vector<int> rv(n+1, -1);
    bool good = true;
    for(int i = 0; good && i < n; i++) {
      lv[i/sz] = min(lv[i/sz], v[i]);
      rv[i/sz] = max(rv[i/sz], v[i]);
      if(i/sz && lv[i/sz] <= rv[i/sz-1]) good = false;
    }
    if(good && n%k == 0) ret.push_back(k);
  }
  if(ret.size() == 0) ret.push_back(-1);
  for(int i = 0; i < ret.size(); i++) cout << ret[i] << "\n";
}