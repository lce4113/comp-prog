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
#define MAXN 1005

bool ps[MAXN], qs[MAXN];
int pageCost[MAXN];
int main() {
  int n, m, s, p, q, v;
  cin >> n >> m >> s >> p >> q;
  s--;
  REP(i,0,p) {
    cin >> v;
    ps[v] = true;
  }
  REP(i,0,q) {
    cin >> v;
    qs[v] = true;
  }
  int pages = (n + m - 1) / m;
  int minPage = INF, maxPage = -1;
  int ans = 0;
  REP(i,0,pages) {
    int l = i * m + 1;
    int r = min(n, (i + 1) * m);
    int qCnt = 0, diffCnt = 0;
    REP(v,l,r+1) {
      if (qs[v]) qCnt++;
      if (ps[v] ^ qs[v]) diffCnt++;
    }
    int selAllCost = 1 + (r - l + 1) - qCnt;
    int deselAllCost = 1 + qCnt;
    pageCost[i] = min(diffCnt, selAllCost);
    if (pageCost[i] > 0) {
      ans += pageCost[i];
      if (minPage == INF) minPage = i;
      maxPage = i;
    }
  }
  if (minPage == INF) s = minPage = maxPage = 0;
  ans += min(abs(maxPage - s), abs(minPage - s)) + maxPage - minPage;
  cout << ans << endl;
  return 0;
}
