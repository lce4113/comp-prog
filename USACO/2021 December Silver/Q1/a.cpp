// ––– USACO 2021 December Silver: Problem A –––

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using db = double;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second

int32_t main() {
  ll k, m, n;
  cin >> k >> m >> n;

  vector<pi> a;
  for (ll i = 0; i < k; i++) {
    ll p, t;
    cin >> p >> t;
    a.pb({p, t});
  }
  for (ll i = 0; i < m; i++) {
    ll f;
    cin >> f;
    a.pb({f, -1});
  }
  sort(a.begin(), a.end());

  priority_queue<pi, vector<pi>> pq1, pq2;
  ll i = 0, x = 0;
  while (a[i].s != -1) {
    x += a[i++].s;
  }
  pq1.push({x, 0});
  while (a[i].s == -1) {
    i++;
  }
  for (; i < k + m;) {
    ll x = 0, start = i;
    while (a[i].s != -1 && i < k + m) {
      x += a[i++].s;
    }
    if (i == k + m) {
      pq1.push({x, start});
      continue;
    } else {
      pq2.push({x, start});
    }
    db lim = (a[i].f - a[start - 1].f) / 2;
    /* cout << a[i].f << ':' << lim << '\n'; */
    map<int, int> pfs;
    ll sm = 0;
    pfs[a[start - 1].f] = sm;
    for (ll k = start; k < i; k++) pfs[a[k].f] = (sm += a[k].s);
    for (ll k = start; k < i; k++) {
      ll dif = (--pfs.lb((db)a[k].f + lim))->s - pfs[a[k - 1].f];
      /* cout << a[k].f << ':' << (db)a[k].f + lim << ' '; */
      pq1.push({dif, start});
    }
    while (a[i].s == -1) {
      i++;
    }
  }

  set<ll> used;
  ll ans = 0;
  for (ll i = n; i >= 1; i--) {
    while (used.count(pq1.top().s)) {
      pq1.pop();
    }
    if (!pq1.size() && !pq2.size()) {
      break;
    }
    pi a = pq1.top();
    used.insert(a.s);
    pq1.pop();
    vector<pi> d;
    /* for (auto &x : used) cout << x << ' '; */
    /* cout << '\n'; */
    while (used.count(pq1.top().s) && pq1.size()) {
      /* cout << pq1.top().f << ',' << pq1.top().s << '\n'; */
      d.pb(pq1.top());
      pq1.pop();
    }
    pi b = pq1.top();
    for (auto &x : d) pq1.push(x);
    pq1.push(a);
    used.erase(a.s);
    if (pq2.size() && pq2.top().f >= a.f + b.f && i >= 2) {
      ans += pq2.top().f;
      /* cout << c.f << ' '; */
      i--;
      used.insert(pq2.top().s);
      pq2.pop();
    } else {
      ans += a.f;
      /* cout << a.f << ' '; */
      used.insert(a.s);
      pq1.pop();
    }
    if (!pq1.size() && !pq2.size()) {
      break;
    }
    /* for (auto &x : used) cout << x << ' '; */
    /* cout << '\n'; */
  }

  cout << ans << '\n';

  /* while (pq1.size()) { */
  /*   cout << pq1.top().f << ',' << pq1.top().s << ' '; */
  /*   pq1.pop(); */
  /* } */
  /* cout << '\n'; */
  /* while (pq2.size()) { */
  /*   cout << pq2.top().f << ',' << pq2.top().s << ' '; */
  /*   pq2.pop(); */
  /* } */
  /* cout << '\n'; */
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
