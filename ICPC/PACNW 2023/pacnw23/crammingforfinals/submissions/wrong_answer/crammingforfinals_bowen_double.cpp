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
typedef pair<double,int> PDI;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;

map<int, vector<PDI>> ranges;
int main() {
  int w, h, d, n;
  cin >> w >> h >> d >> n;
  REP(i,0,n) {
    int x, y;
    cin >> x >> y;
    REP(dy,-d,d+1) {
      int cy = y + dy;
      if (cy < 1 || cy > h) continue;
      double dx = sqrt((double)d * d - dy * dy);
      double lx = max(1.0, x - dx), rx = min((double)w, x + dx);
      ranges[cy].push_back(PDI(lx, -1));
      ranges[cy].push_back(PDI(rx, 1));
    }
    ranges[y].push_back(PDI(x, -2));
  }
  if (ranges.size() != h) return cout << 0 << endl, 0;
  int ans = INF;
  for (auto &rsi: ranges) {
    auto rs = rsi.second;
    sort(rs.begin(), rs.end());
    int sol = 0;
    double lastX = 0;
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

      int ranr = (int)rs[i].first - (floor(rs[i].first) == rs[i].first ? 1 : 0);
      int ranl = ceil(lastX) + (ceil(lastX) == lastX ? 1 : 0);
      if (ranl <= ranr) ans = min(sol, ans);
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
