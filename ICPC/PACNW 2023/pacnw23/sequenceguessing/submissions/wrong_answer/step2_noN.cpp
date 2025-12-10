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
#define MAXN 100001

int main() {
  VI used(MAXN, -1);
  int k = 0;
  for (int i = 0; i < MAXN - 1; i += 2) {
    used[i] = ++k;
  }
  cout << k << endl;
  cout.flush();
  bool done = false;
  while (!done) {
    int x;
    cin >> x;
    if (x == -1) {
      REP(i,0,MAXN) if (used[i] != -1) cout << i << " ";
      cout << endl;
      done = true;
    }
    else {
      cout << used[x] << endl;
    }
    cout.flush();
  }
  return 0;
}
