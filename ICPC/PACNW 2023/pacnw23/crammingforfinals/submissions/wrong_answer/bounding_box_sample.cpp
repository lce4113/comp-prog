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

const int INF = (int)1E9;
const int MAX_TRY = 20000000;
const int TIME_LIMIT_MS = 5850;

typedef unsigned int uint;
uint RA = 7919, RB = 1321;
int myrand(int P){
	RA = 18000 * (RA&65535) + (RA>>16);
	RB = 36969 * (RB&65535) + (RB>>16);
	return ((RB<<16)+RA)%P;
}

set<PII> pointSet;
vector<PII> points;
vector<PII> cands;
int main() {
  srand(42);
  int w, h, d, n;
  cin >> w >> h >> d >> n;
  ll d2 = (ll)d * d;
  bool useSample = (ll)(2 * d + 1) * (2 * d + 1) * n > MAX_TRY;
  double keepRatio = useSample ? MAX_TRY / ((double)(2 * d + 1) * (2 * d + 1) * n) : 1.0;
  // int randThreshold = (int)(keepRatio * RAND_MAX);
  REP(i,0,n) {
    int x, y;
    cin >> x >> y;
    points.push_back(PII(x, y));
    pointSet.insert(PII(x, y));
    int take = keepRatio * (2 * d + 1) * (2 * d + 1);
    if (!useSample) {
      REP(dx,-d,d+1) REP(dy,-d,d+1) {
        int cx = x + dx, cy = y + dy;
        if (cx < 1 || cx > w || cy < 1 || cy > h) continue;
        cands.push_back(PII(x + dx, y + dy));
      }
    }
    else {
      REP(j,0,take) {
        int dx = -d + myrand(2 * d + 1);
        int dy = -d + myrand(2 * d + 1);
        int cx = x + dx, cy = y + dy;
        if (cx < 1 || cx > w || cy < 1 || cy > h) continue;
        cands.push_back(PII(x + dx, y + dy));
      }
    }
  }
  int ans = INF;
  auto start = high_resolution_clock::now();
  REP(i,0,cands.size()) {
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
