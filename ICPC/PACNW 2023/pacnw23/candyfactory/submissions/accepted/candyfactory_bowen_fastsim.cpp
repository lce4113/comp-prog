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

int main() {
  int n, k;
  cin >> n >> k;
  VI q(n + 1, 0);
  REP(i,0,n) cin >> q[i];
  while (true) {
    sort(q.begin(), q.end(), greater<int>());
    int cntk = 0, sk, ek;
    REP(i,0,n) {
      int j = i;
      while (j < n && q[j] == q[i]) j++;
      cntk += j - i;
      if (cntk >= k) {
        sk = i;
        ek = j - 1;
        break;
      }
      i = j - 1;
    }

    if (q[sk] == 0) {
      ll ans = 0;
      for (int i = sk - 1; i >= 0; i--) ans += (ll)(q[i] - q[i + 1]) * (k - i - 1);
      cout << ans << endl;
      return 0;
    }

    int shortage = 0;
    while (ek + 1 < n && q[ek + 1] == q[sk] - 1) {
      ek++;
      shortage++;
    }

    if (sk == 0) {
      int rem = ((ll)(ek - sk + 1) * (q[sk] - q[ek + 1]) - shortage) % k;
      REP(i,0,ek+1) q[i] = q[ek + 1] + (i < rem ? 1 : 0);
      continue;
    }

    int l = q[ek + 1] + 1, r = q[sk - 1];
    ll has = (ll)(ek - sk + 1) * q[sk] - shortage;
    while (l <= r) {
      int m = (l + r) / 2;
      int g = q[sk - 1] - m;
      ll need = (ll)(k - sk) * g;
      ll has2 = has - need;
      int h = has2 / (ek - sk + 1) + (has2 % (ek - sk + 1) ? 1 : 0);
      if (has2 < 0 || m < h) l = m + 1;
      else r = m - 1;
    }
    int g = q[sk - 1] - l;
    REP(i,0,sk) q[i] -= g;
    ll need = (ll)(k - sk) * g;
    ll has2 = has - need;
    int h = has2 / (ek - sk + 1);
    int rem = has2 % (ek - sk + 1);
    REP(i,sk,ek+1) {
      q[i] = h;
      if (i - sk < rem) q[i]++;
    }
  }
  return 0;
}
