#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

mt19937 gs(14004);
bool flip_coin(double p) {
  return uniform_real_distribution<double>(0, 1)(gs) < p;
}

int main() {
  int n;
  cin >> n;
  vector<double> p(n);
  for(auto& x: p) cin >> x;
  long long nn = 0;
  long long dd = 0;
  while(dd < 1000000) {
    dd++;
    int mask = (1 << n) - 1;
    while(__builtin_popcount(mask) > 2) {
      nn++;
      int on = 0;
      int off = 0;
      for(int i = 0; i < n; i++) {
        if((mask&(1<<i)) == 0) continue;
        if(flip_coin(p[i])) on |= (1 << i);
        else off |= (1 << i);
      }
      if(__builtin_popcount(on) == 1) mask ^= on;
      if(__builtin_popcount(off) == 1) mask ^= off;
    }
  }
  cout << fixed << setprecision(17) << nn/(double)dd << "\n";
}