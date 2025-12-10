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

using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 30005
#define MAXM 20

int n, m;
char g[MAXN][MAXM + 1];
VI jobMasks[MAXM + 1];
bool teamUsed[MAXN];
bool matchSolved;

time_point<high_resolution_clock> start;
bool timeout;
int solveMatchCounter = 0;
bool checkTimeout() {
  time_point<high_resolution_clock> stop = high_resolution_clock::now();
  duration<double, std::milli> d = stop - start;
  if (d.count() >= 975) timeout = true;
  return timeout;
}
void solveMatch(int j, VI &jobs) {
  if (++solveMatchCounter % 1000000 == 0) {
    if (checkTimeout()) return;
  }
  if (matchSolved) return;
  if (j == jobs.size()) {
    matchSolved = true;
    return;
  }
  if (timeout) return;
  REP(i,0,n) {
    if (teamUsed[i] || g[i][jobs[j]] == '0') continue;
    teamUsed[i] = true;
    solveMatch(j + 1, jobs);
    teamUsed[i] = false;
    if (matchSolved || timeout) return;
  }
}

bool hasMatch(VI &jobs) {
  matchSolved = false;
  solveMatch(0, jobs);
  return matchSolved;
}

bool isRobust(VI &testJobMasks) {
  for (auto &jobMask: testJobMasks) {
    VI jobs;
    REP(j,0,m) if (jobMask & (1 << j)) jobs.push_back(j);
    if (!hasMatch(jobs)) {
      return false;
    }
    if (checkTimeout()) return false;
  }
  return true;
}
int main() {
  start = high_resolution_clock::now();
  cin >> n >> m;
  REP(i,0,n) cin >> g[i];

  REP(maskJob,1,1<<m) {
    int jobCount = __builtin_popcount(maskJob);
    VI jobs;
    jobMasks[jobCount].push_back(maskJob);
  }

  int ans = 0;
  REP(k,1,m+1) {
    if (isRobust(jobMasks[k])) ans = k;
    if (timeout) break;
  }
  cout << ans << endl;
  return 0;
}
