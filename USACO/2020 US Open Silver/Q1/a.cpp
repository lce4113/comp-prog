// USACO 2020 US Open Silver: Problem A

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pi = pair<int, int>;
#define pb push_back
#define f first
#define s second

int n, m;
map<int, int> a;

bool cont(int x) {
  int y = (--a.upper_bound(x))->s;
  if (x <= y) return true;
  return false;
}

bool test(int x) {
  for (int i = 1, curr = a.begin()->f; i <= n; i++, curr += x) {
    if (curr > a.rbegin()->s) return false;
    if (!cont(curr)) curr = a.lower_bound(curr)->f;
  }
  return true;
}

int bin(int l, int r) {
  int m = (l + r) / 2;
  if (test(m) && r - l == 1) return l;
  if (test(m)) return bin(m, r);
  return bin(l, m);
}

int32_t main() {
  ifstream cin("socdist.in");
  ofstream cout("socdist.out");

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    a[x] = y;
  }

  int maxd = (a.rbegin()->s - a.begin()->f) / (n - 1);
  int ans = bin(1, maxd + 1);
  /* cout << test(2) << '\n'; */
  cout << ans << '\n';
}
