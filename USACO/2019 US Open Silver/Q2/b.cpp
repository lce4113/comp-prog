// USACO 2019 US Open Silver: Problem B

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll

using vi = vector<int>;
using pi = pair<int, int>;
using db = double long;
#define pb push_back
#define f first
#define s second

int n;
vector<pair<pair<pi, pi>, int>> a;

bool intersect(int i, int k) {
  db m = (a[i].f.f.s - a[i].f.s.s) / (a[i].f.f.f - a[i].f.s.f);
  db b = a[i].f.f.s - m * a[i].f.f.f;
  db x = a[k].f.f.f * m + b - a[k].f.f.s;
  db y = a[k].f.f.s * m + b - a[k].f.s.s;
  return (x >= 0 && y <= 0) || (x <= 0 && y >= 0);
}
bool check(int i) {
  int ans = 0;
  for (int k = 0; k < n; k++)
    if (intersect(i, k)) ans++;
  return ans;
}

int32_t main() {
  ifstream cin("cowjump.in");
  ofstream cout("cowjump.out");

  cin >> n;

  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 < x2)
      a.pb({{{x1, y1}, {x2, y2}}, i});
    else
      a.pb({{{x2, y2}, {x1, y1}}, i});
  }

  sort(a.begin(), a.end());

  priority_queue<pi> ends;
  set<pair<pi, int>> active;
  for (int i = 0; i < n; i++) {
    while (ends.top().f < a[i].f.s.f) {
      active.erase(
          {{a[ends.top().s].f.f.s, a[ends.top().s].f.s.s}, ends.top().s});
      ends.pop();
    }
    ends.push({a[i].f.s.f, i});
    active.insert({{a[i].f.f.s, a[i].f.s.s}, i});
    auto x = active.upper_bound({{a[i].f.f.s, a[i].f.s.s}, i});
    x--;
    if (intersect(x->s, i)) {
      if (check(x->s) > check(i)) {
        cout << x->s + 1;
      } else {
        cout << a[i].s + 1;
      }
    }
    x++, x++;
    if (intersect(x->s, i)) {
      if (check(x->s) > check(i)) {
        cout << x->s + 1;
      } else {
        cout << a[i].s + 1;
      }
    }
  }
}
