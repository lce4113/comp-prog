// ––– USACO 2020 February Bronze: Problem A –––

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

int getArea(pi a, pi b, pi c) {
  int area = 1;
  bool fdone = false, sdone = false;
  pi pts[3] = {a, b, c};
  for (int i = 0; i < 3; i++) {
    pi a = pts[i];
    pi b = pts[(i + 1) % 3];
    if (a.f == b.f && !fdone) {
      area *= abs(a.s - b.s);
      fdone = true;
    }
    if (a.s == b.s && !sdone) {
      area *= abs(a.f - b.f);
      sdone = true;
    }
  }
  return area;
}

int main()
{
  ifstream cin("triangles.in");
  ofstream cout("triangles.out");

  int n;
  cin >> n;

  vector<pi> pts;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    pts.pb(mp(x, y));
  }

  int ans = -1;
  for (int i = 0; i < n; i++) {
    for (int k = i + 1; k < n; k++) {
      for (int l = k + 1; l < n; l++) {
        int area = getArea(pts[i], pts[k], pts[l]);
        if (area > ans) ans = area;
      }
    }
  }
  cout << ans << '\n';
}
