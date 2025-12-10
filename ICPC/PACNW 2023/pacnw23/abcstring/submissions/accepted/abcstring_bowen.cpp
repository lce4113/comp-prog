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

int cnt[8];
int main() {
  string s;
  cin >> s;
  int ans = 0;
  for (auto &ch: s) {
    int c = 1 << (ch - 'A');
    int matchToFull = c ^ 7;
    if (cnt[matchToFull]) cnt[matchToFull]--;
    else {
      bool fit = false;
      REP(i,0,3) {
        if ((1 << i) & c) continue;
        if (cnt[1 << i]) {
          cnt[1 << i]--;
          cnt[(1 << i) | c]++;
          fit = true;
          break;
        }
      }
      if (!fit) cnt[c]++;
    }
    int sol = 0;
    REP(m,1,7) sol += cnt[m];
    ans = max(ans, sol);
  }
  cout << ans << endl;
  return 0;
}
