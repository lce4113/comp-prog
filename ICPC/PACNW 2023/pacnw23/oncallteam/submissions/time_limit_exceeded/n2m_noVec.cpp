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
int t[MAXN], T;
int seen[MAXN];
int n, m;
void solve(int j, int mSize, int seenCnt) {
  if (seenCnt < mSize) { // early break
    ok[mSize] = false;
    return;
  }
  if (!ok[mSize]) return; // early break

  if (j == m) return;

  solve(j + 1, mSize, seenCnt);
  for (auto &i: eng[j]) {
    if (seen[i] == 0) seenCnt++;
    seen[i]++;
  }
  solve(j + 1, mSize + 1, seenCnt);
  for (auto &i: eng[j]) seen[i]--;
}

int main() {
  cin >> n >> m;
  REP(i,0,n) cin >> g[i];
  REP(j,0,m) {
    REP(i,0,n) if (g[i][j] == '1') eng[j].push_back(i);
  }
  FILL(ok, true);
  solve(0, 0, 0);
  int ans = 0;
  REP(k,0,m+1) {
    if (ok[k]) ans = k;
    else break;
  }
  cout << ans << endl;
  return 0;
}
