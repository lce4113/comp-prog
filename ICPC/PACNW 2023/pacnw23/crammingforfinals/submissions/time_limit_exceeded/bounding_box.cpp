#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;

set<PII> pointSet;
vector<PII> points;
int main() {
  int w, h, d, n;
  cin >> w >> h >> d >> n;
  ll d2 = (ll)d * d;
  set<PII> cands;
  REP(i,0,n) {
    int x, y;
    cin >> x >> y;
    points.push_back(PII(x, y));
    pointSet.insert(PII(x, y));
    REP(dx,-d,d+1) REP(dy,-d,d+1) {
      int cx = x + dx, cy = y + dy;
      if (cx < 1 || cx > w || cy < 1 || cy > h) continue;
      cands.insert(PII(x + dx, y + dy));
    }
  }
  int ans = INF;
  for (auto &c: cands) {
    if (pointSet.find(c) != pointSet.end()) continue;
    int sol = 0;
    for (auto &p: points) {
      ll dx = p.first - c.first;
      ll dy = p.second - c.second;
      if (dx * dx + dy * dy <= d2) sol++;
    }
    ans = min(ans, sol);
  }
  cout << ans << endl;
  return 0;
}
