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
int t[MAXN];
int main() {
  int n, m;
  cin >> n >> m;
  REP(i,0,n) cin >> g[i];
  REP(j,0,m) {
    REP(i,0,n) if (g[i][j] == '1') eng[j].push_back(i);
  }
  FILL(ok, true);
  FILL(t, -1);
  REP(maskJob,0,1<<m) {
    int k = __builtin_popcount(maskJob);
    int cnt = 0;
    REP(j,0,m) {
      if (!(maskJob & (1 << j))) continue;
      for (auto &i: eng[j]) {
        if (t[i] < maskJob) {
            t[i] = maskJob;
            cnt++;
        }
        if (cnt >= k) break;
      }
      if (cnt >= k) break;
    }
    if (cnt < k) ok[k] = false;
  }
  int ans = 0;
  REP(k,0,m+1) {
    if (ok[k]) ans = k;
    // else break;
  }
  cout << ans << endl;
  return 0;
}
