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

#define MAXN 30005
#define MAXM 20

char g[MAXN][MAXM + 1];
VI eng[MAXM];
int ok[MAXM + 1];
VI neighbors[1 << MAXM];
int t[MAXN];
int main() {
  int n, m;
  cin >> n >> m;
  REP(i,0,n) cin >> g[i];
  REP(j,0,m) {
    REP(i,0,n) if (g[i][j] == '1') eng[j].push_back(i);
  }
  FILL(ok, true);
  REP(maskJob,1,1<<m) {
    int k = __builtin_popcount(maskJob);
    int j = -1;
    REP(jc,0,m) {
      if (maskJob & (1 << jc)) {
        j = jc;
        break;
      }
    }
    int prevMask = maskJob ^ (1 << j);
    VI &nb = neighbors[maskJob];
    for (auto &i: neighbors[prevMask]) {
      t[i] = maskJob;
      nb.push_back(i);
    }
    for (auto &i: eng[j]) {
      if (t[i] < maskJob) {
        t[i] = maskJob;
        nb.push_back(i);
        if (nb.size() >= m) break;
      }
    }
    if (nb.size() < k) ok[k] = false;
  }
  int ans = 0;
  REP(k,0,m+1) {
    if (ok[k]) ans = k;
    else break;
  }
  cout << ans << endl;
  return 0;
}
