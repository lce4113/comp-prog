// CSES Sorting & Searching: Concert Tickets

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

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
  int c[m];
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    c[i] = x;
  }

  for (int i = 0; i < m; i++) {
    auto r = t.upper_bound(c[i]);
    if (r == t.begin()) {
      cout << -1 << '\n';
      continue;
    }
    auto l = prev(r);
    cout << *l << '\n';
    t.erase(l);
  }
}
