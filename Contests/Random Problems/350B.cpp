// ––– CodeForces Contest 350, Problem B: "Resort" –––

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
using str = string;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  map<int, vi> a;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x) {
      vi y;
      y.pb(i);
      a[i] = y;
    }
  }

  int b[n + 1];
  set<int> c, d;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    b[i] = x;
    if (c.count(x)) {
      d.insert(x);
    }
    c.insert(x);
  }

  for (int i = 1; i <= n; i++) {
    if (d.count(b[i])) {
      b[i] = 0;
    }
  }

  int m = -1;
  for (auto& x : a) {
    int e = x.f;
    while (true) {
      e = b[e];
      if (a[e].size() == 1 || e == 0) {
        break;
      }
      x.s.pb(e);
    }
    if (x.s.size() > a[m].size()) {
      m = x.f;
    }
  }

  cout << a[m].size() << '\n';
  for (int i = a[m].size() - 1; i >= 0; i--) {
    cout << a[m][i] << ' ';
  }
  cout << '\n';
}
