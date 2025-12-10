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

#define MAXD 5000
const int INF = (int)1E9;

int dxByDy[MAXD];
map<int, vector<PII>> events;
int main() {
  int w, h, d, n;
  cin >> w >> h >> d >> n;
  REP(dy,0,d+1) {
    REP(dx,0,d+1) {
      if ((ll)dy * dy + (ll)dx * dx <= (ll)d * d) dxByDy[dy] = dx;
      else break;
    }
  }
  REP(i,0,n) {
    int x, y;
    cin >> x >> y;
    REP(dy,-d,d+1) {
      int cy = y + dy;
      if (cy < 1 || cy > h) continue;
      int dx = dxByDy[abs(dy)];
      int lx = max(1, x - dx), rx = min(w, x + dx);
      events[cy].push_back(PII(lx, -1));
      events[cy].push_back(PII(rx, 1));
    }
    events[y].push_back(PII(x, -2));
  }
  if (events.size() != h) return cout << 0 << endl, 0;
  int ans = INF;
  for (auto &rsi: events) {
    auto rs = rsi.second;
    sort(rs.begin(), rs.end());
    int sol = 0, lastX = 0;
    REP(i,0,rs.size()) {
      int j = i;
      int inc = 0, dec = 0, block = 0;
      while (j < rs.size() && rs[j].first == rs[i].first) {
        if (rs[j].second == -1) inc++;
        else if (rs[j].second == 1) dec++;
        else block = 1;
        j++;
      }
      i = j - 1;

      if (rs[i].first - lastX > 1) ans = min(ans, sol);
      lastX = rs[i].first;

      sol += inc;
      if (!block) ans = min(ans, sol);
      sol -= dec;
    }
    if (lastX < w) return cout << 0 << endl, 0;
  }
  cout << ans << endl;
  return 0;
}
