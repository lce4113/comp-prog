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
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

#define MAXD 2501
const int TIME_LIMIT_MS = 5850;
const int SAMPLE_SIZE = 1;

typedef unsigned int uint;
uint RA = 7919, RB = 1321;
int myrand(int P){
	RA = 18000 * (RA&65535) + (RA>>16);
	RB = 36969 * (RB&65535) + (RB>>16);
	return ((RB<<16)+RA)%P;
}

int dxByDy[MAXD];
set<PII> pointSet;
vector<PII> points;
PII cands[20000005];
int main() {
  srand(42);
  int w, h, d, n;
  cin >> w >> h >> d >> n;
  ll d2 = (ll)d * d;
  REP(dy,0,d+1) {
    REP(dx,0,d+1) {
      if ((ll)dy * dy + (ll)dx * dx <= d2) dxByDy[dy] = dx;
      else break;
    }
  }
  int C = 0;
  REP(i,0,n) {
    int x, y;
    cin >> x >> y;
    points.push_back(PII(x, y));
    pointSet.insert(PII(x, y));
    REP(dy,-d,d+1) {
      REP(it,0,2) {
        int dx = (it == 0 ? -1 : 1) * dxByDy[abs(dy)];
        REP(ddx,0,SAMPLE_SIZE+1) {
          int cx = x + dx + ddx, cy = y + dy;
          if (cx < 1 || cx > w || cy < 1 || cy > h) continue;
          cands[C++] = PII(cx, cy);
        }
      }
    }
    if (y + d + 1 <= h) cands[C++] = PII(x, y + d + 1);
    if (y - d - 1 >= 1) cands[C++] = PII(x, y - d - 1);
  }
  REP(i,0,C) {
    int j = myrand(i + 1);
    swap(cands[i], cands[j]);
  }
  int ans = n;
  auto start = high_resolution_clock::now();
  REP(i,0,C) {
    if (i % 1000 == 0) {
      auto stop = high_resolution_clock::now();
      duration<double, std::milli> d = stop - start;
      if (d.count() >= TIME_LIMIT_MS) break;
    }
    auto c = cands[i];
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
