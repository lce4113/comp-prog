// CodeForces Educational Round 146: Problem C

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define pb push_back
using pi = pair<int, int>;
#define f first
#define s second

void solve() {
  int n, s1, s2;
  cin >> n >> s1 >> s2;
  vector<pi> r(n);
  for (int i = 0; i < n; i++) {
    cin >> r[i].f;
    r[i].s = i + 1;
  }
  sort(r.rbegin(), r.rend());
  int curr1 = s1, curr2 = s2;
  vi a, b;
  for (int i = 0; i < n; i++) {
    if (curr1 <= curr2) {
      a.pb(r[i].s);
      curr1 += s1;
    } else {
      b.pb(r[i].s);
      curr2 += s2;
    }
  }
  cout << a.size() << ' ';
  for (auto x : a) cout << x << ' ';
  cout << '\n';
  cout << b.size() << ' ';
  for (auto x : b) cout << x << ' ';
  cout << '\n' << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
