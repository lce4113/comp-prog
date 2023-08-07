// USACO 2023 February Silver: Problem C

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define lb lower_bound
#define f first
#define s second
#define int long long

vector<int> curr;
map<int, set<pair<int, pair<int, int>>>> flights;

void rec(int a, int t) {
  if (curr[a] == -1 || t < curr[a])
    curr[a] = t;
  else
    return;

  /* cout << (flights[a].lb({t, {-1, -1}})->s).s << '\n'; */
  vector<pair<int, pair<int, int>>> todo;
  for (auto i = flights[a].lb({t, {-1, -1}}); i != flights[a].end(); i++)
    todo.pb(*i);
  flights[a].erase(flights[a].lb({t, {-1, -1}}), flights[a].end());
  for (auto i : todo) {
    /* cout << i.s.f << ' ' << i.s.s << '\n'; */
    rec(i.s.f, i.s.s);
  }
}

int32_t main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i <= n; i++) curr.pb(-1);

  map<int, set<pair<int, pair<int, int>>>> flights0;
  for (int i = 0; i < m; i++) {
    int c, r, d, t;
    cin >> c >> r >> d >> t;
    flights0[c].insert({r, {d, t}});
  }

  int b = -1;
  for (auto x : flights0) {
    int a;
    cin >> a;
    if (b == -1) b = a;
    for (auto k : x.s) flights[x.f].insert({k.f - a, k.s});
  }

  rec(1, -b);
  /* for (auto x : flights) { */
  /*   cout << x.f << " : "; */
  /*   for (auto k : x.s) cout << k.f << ' ' << k.s.f << ' ' << k.s.s << ", ";
   */
  /*   cout << '\n'; */
  /* } */
  curr[1] = 0;
  /* for (auto x : curr) cout << x.f << ' ' << x.s << '\n'; */
  for (int i = 1; i <= n; i++) cout << curr[i] << '\n';
}
