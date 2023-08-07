// USACO 2020 February Silver: Problem A

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
#define ll long long

int32_t main() {
  freopen("swap.in", "r", stdin);
  // the following line creates/overwrites the output file
  freopen("swap.out", "w", stdout);

  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> a;
  for (ll i = 0; i < n; i++) a.pb(i);
  for (ll i = 0; i < m; i++) {
    ll l, r;
    cin >> l >> r;
    l--, r--;
    vector<ll> x;
    for (ll i = l; i <= r; i++) x.pb(a[i]);
    for (ll i = l; i <= r; i++) a[i] = x[r - l - (i - l)];
  }

  set<ll> left;
  map<ll, ll> ans;
  for (ll i = 0; i < n; i++) left.insert(i);
  while (left.size()) {
    ll start = *left.begin();
    ll x = a[start];
    vector<ll> cycle(1, start);
    left.erase(start);
    if (start == x) {
      ans[start] = start;
      continue;
    }
    left.erase(x);
    while (x != start) {
      cycle.pb(x);
      x = a[x];
      left.erase(x);
    }
    for (ll i = 0; i < cycle.size(); i++) {
      ans[cycle[i]] = cycle[(i + k) % cycle.size()];
    }
  }

  for (auto &x : ans) cout << (x.s + 1) << '\n';
}
