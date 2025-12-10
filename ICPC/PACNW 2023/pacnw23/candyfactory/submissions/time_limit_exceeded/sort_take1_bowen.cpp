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
#define MAXN 100005

int main() {
  int n, k;
  cin >> n >> k;
  VI quantity(n,0);
  REP(i,0,n) cin >> quantity[i];
  ll ans = 0;
  while (true) {
    sort(quantity.begin(), quantity.end(), greater<int>());
    if (quantity[0] == 0) break;
    REP(i,0,k) {
      if (quantity[i] > 0) quantity[i]--;
      else ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
