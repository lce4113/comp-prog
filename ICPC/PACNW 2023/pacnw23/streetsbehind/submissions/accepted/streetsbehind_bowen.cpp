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

int main() {
  int T;
  cin >> T;
  while (T--) {
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    n += k;
    ll ans = 0;
    while (k > 0) {
      ll x = n - k;
      ll y = x * (b - a) / a;
      if (y == 0) {
        ans = -1;
        break;
      }
      ll l = 1, r = (k + y - 1) / y; // number of times to train with this y
      while (l <= r) {
        ll m = (l + r) / 2;
        ll k2 = max(0LL, k - (m - 1) * y);
        ll x2 = n - k2;
        ll y2 = x2 * (b - a) / a;
        if (y2 > y) r = m - 1;
        else l = m + 1;
      }
      k -= min(k, y * r);
      ans += r;
    }
    cout << ans << endl;
  }
  return 0;
}
