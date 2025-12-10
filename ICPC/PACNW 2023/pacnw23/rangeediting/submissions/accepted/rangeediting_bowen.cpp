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

int dp[MAXN][MAXN], val[MAXN];
int solve(int l, int r) {
  if (l == r) return 0;
  if (dp[l][r] != -1) return dp[l][r];
  int ans = INF;
  REP(i,l,r) {
    int sol = solve(l, i) + solve(i + 1, r) + (val[l] != val[i + 1]);
    ans = min(ans, sol);
  }
  dp[l][r] = ans;
  return ans;
}
int main() {
  int n;
  cin >> n;
  REP(i,1,n+1) cin >> val[i];
  FILL(dp, -1);
  cout << solve(0, n) << endl;
  return 0;
}
