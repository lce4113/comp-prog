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
#define MAXN 505

int N, deg[MAXN];
VI adj[MAXN], seqAdj[MAXN];
bool edge[MAXN][MAXN], used[MAXN], usedSeq[MAXN], v[MAXN];
int dp[MAXN][2];

void solve(int x, int p) {
  VI gap;
  int base = 0;
  for (auto &y: seqAdj[x]) {
    if (y == p || usedSeq[y]) continue;
    solve(y, x);
    gap.push_back(dp[y][1] - dp[y][0]);
    base += dp[y][0];
  }
  sort(gap.begin(), gap.end());
  int sz = gap.size();
  dp[x][0] = dp[x][1] = base;
  if (sz >= 2) {
    dp[x][0] = max(dp[x][0], base + gap[sz - 1] + gap[sz - 2] + 2);
  }
  if (sz >= 1) {
    dp[x][1] = max(dp[x][1], base + gap[sz - 1] + 1);
    dp[x][0] = max(dp[x][0], dp[x][1]);
  }
}

bool possible(VI &seq, int k) {
  if (seq.size() == N) return k == 0;
  FILL(usedSeq, false);
  for (auto &v: seq) usedSeq[v] = true;
  int last = seq.back();
  FILL(deg, 0);
  REP(i,1,N+1) seqAdj[i].clear();
  int maxDeg = 0;
  VI neighbors;
  REP(i,1,N+1) {
    if (usedSeq[i]) continue;
    if (edge[i][last]) neighbors.push_back(i);
    for (auto &j: adj[i]) {
      if (!usedSeq[j] && edge[j][i]) {
        seqAdj[i].push_back(j);
        maxDeg = max(maxDeg, ++deg[j]);
      }
    }
  }
  bool onlyOneWhite = maxDeg > 0 && maxDeg == N - seq.size() - 1;
  FILL(dp, -1);
  int length = 0, maxGap = 0;
  for (auto &v: neighbors) {
    solve(v, last);
    length += dp[v][0];
    maxGap = max(dp[v][1] + 1 - dp[v][0], maxGap);
  }
  length += maxGap;
  REP(i,1,N+1) {
    if (!usedSeq[i] && dp[i][0] == -1) {
      solve(i, -1);
      length += dp[i][0];
    }
  }
  int l, r;
  if (neighbors.size() == N - seq.size()) l = r = 1;
  else {
    l = onlyOneWhite;
    r = length;
  }
  return l <= k && k <= r;
}

int main() {
  int K;
  cin >> N >> K;
  K = N - 1 - K;
  REP(i,0,N-1) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    edge[a][b] = edge[b][a] = true;
  }
  VI seq;
  REP(p,1,N+1) {
    REP(i,1,N+1) {
      if (used[i]) continue;
      seq.push_back(i);
      int sz = seq.size();
      bool lastEdge = false;
      if (seq.size() >= 2 && edge[seq[sz - 1]][seq[sz - 2]]) {
        K--;
        lastEdge = true;
      }
      if (possible(seq, K)) {
        used[i] = true;
        break;
      }
      seq.pop_back();
      if (lastEdge) K++;
    }
    if (seq.size() != p) return cout << -1 << endl, 0;
  }
  REP(i,0,N-1) cout << seq[i] << " ";
  cout << seq.back() << endl;
  return 0;
}
