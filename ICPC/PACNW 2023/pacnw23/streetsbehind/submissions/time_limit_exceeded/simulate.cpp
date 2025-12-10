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
      k -= min(k, y);
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
