// ––– CodeForces Contest 834, Problem B: "The Festive Evening" –––

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

  int n, k;
  cin >> n >> k;

  map<char, pi> a;
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    if (!a.count(x)) {
      a[x] = { i, i };
    } else {
      a[x].s = i;
    }
  }

  vector<array<int, 3>> b;
  for (auto& x : a) {
    b.pb({ x.s.f, 0, x.f });
    b.pb({ x.s.s, 1, x.f });
  }

  sort(b.begin(), b.end());

  set<int> c;
  for (auto& x : b) {
    if (x[1]) {
      c.erase(x[2]);
    } else {
      c.insert(x[2]);
    }
    if (c.size() > k) {
      cout << "YES" << '\n';
      return 0;
    }
  }

  cout << "NO" << '\n';
}
