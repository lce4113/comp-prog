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
  ll sum = 0;
  int maxq = 0, q;
  REP(i,0,n) {
    cin >> q;
    sum += q;
    maxq = max(maxq, q);
  }
  cout << max((ll)k * maxq, (sum + k - 1) / k * k) - sum << endl;
  return 0;
}
