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
#define MAXN 30005
#define MAXM 20

char g[MAXN][MAXM + 1];
bool dp[2][1 << MAXM];
bool ok[MAXM + 1];
int jMaskToj[1 << MAXM];
int main() {
  int n, m;
  cin >> n >> m;
  REP(i,0,n) cin >> g[i];
  int cur = 0, pre = 1;
  dp[0][0] = true;
  REP(j,0,m) jMaskToj[1 << j] = j;
  REP(i,0,n) {
    pre ^= 1; cur ^= 1;
    REP(maskJob,0,1 << m) {
      if (!dp[pre][maskJob]) continue;
      dp[cur][maskJob] = true;

      int mask = (1 << m) - 1 - maskJob;
      while (mask > 0) {
        int jMask = -mask & mask;
        int j = jMaskToj[jMask];
        if (g[i][j] == '1') dp[cur][maskJob | jMask] = true;
        mask ^= jMask;
      }
    }
  }
  REP(k,0,m+1) ok[k] = true;
  REP(maskJob,0,1 << m) {
    if (!dp[cur][maskJob]) {
        ok[__builtin_popcount(maskJob)] = false;
    }
  }
  int ans = 0;
  REP(k,0,m+1) {
    if (ok[k]) ans = k;
    else break;
  }
  cout << ans << endl;
  return 0;
}
