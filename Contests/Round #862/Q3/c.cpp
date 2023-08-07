// ––– CodeForces Round #862: Problem C –––

#include <bits/stdc++.h>
using namespace std;

#define int long long
using vi = vector<int>;
#define pb push_back
using pi = pair<int, int>;
#define f first
#define s second
using db = long double;

void solve() {
  int n, m;
  cin >> n >> m;
  set<int> lines;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    lines.insert(x);
  }
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    /* cout << a << b << c << '\n'; */
    if (c <= 0) {
      cout << "NO\n";
      continue;
    }
    db l = b - 2 * sqrt(a * c), r = b + 2 * sqrt(a * c);
    auto it2 = lines.lower_bound(b), it1 = it2;
    it1--;
    int x1 = *it1, x2 = *it2;
    if (4 * a * c > (b - x1) * (b - x1) && it1 != lines.end()) {
      cout << "YES\n" << x1 << '\n';
      continue;
    }
    if (4 * a * c > (b - x2) * (b - x2) && it2 != lines.end()) {
      cout << "YES\n" << x2 << '\n';
      continue;
    }
    cout << "NO\n";
  }
  /* cout << '\n'; */
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
