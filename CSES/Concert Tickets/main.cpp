// ––– CSES Concert Tickets –––

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

bool cmp(pi a, pi b) {
  return a.f > b.f;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  multiset<int> t;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    t.insert(x);
  }
  pi c[m];
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    c[i] = mp(x, i);
  }

  sort(c, c + m, cmp);

  for (int i = 0; i < m; i++) {
    cout << c[i].f << ' ' << c[i].s << '\n';
  }
  cout << '\n';

  for (auto i = t.begin(); i != t.end(); i++) {
    cout << *i << ' ';
  }
  cout << '\n';

  int ans[m];
  for (int i = 0; i < m; i++) {
    auto r = t.upper_bound(c[i].f);
    if (*r == *t.rbegin()) {
      ans[c[i].s] = -1;
      continue;
    }
    auto l = prev(r);
    cout << *r << ' ' << *l << '\n';
    ans[c[i].s] = *t.rbegin();
    t.erase(t.find(*l));
  }

  for (int i = 0; i < m; i++) {
    cout << ans[i] << '\n';
  }
}
