// CodeForces Round #865: Problem D

#include <bits/stdc++.h>
using namespace std;

void g(vector<int> a, vector<int> b) {
  cout << "! ";
  for (auto x : a) cout << x << ' ';
  for (auto x : b) cout << x << ' ';
  cout << endl;
}

void add(int x) {
  cout << "+ " << x << endl;
}

int q(int i, int k) {
  cout << "? " << i << ' ' << k << endl;
  int r;
  cin >> r;
  return r;
}

void solve() {
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
