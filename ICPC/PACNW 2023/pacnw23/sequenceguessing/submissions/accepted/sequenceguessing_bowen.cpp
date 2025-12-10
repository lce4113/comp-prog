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
  int k = 33333 * 2 + 2;
  VI used(MAXN, -1);
  REP(i,0,MAXN) {
    if (i % 3 == 0) used[i] = i / 3 * 2 + 1;
    else if (i == MAXN - 1) used[i] = k;
  }
  cout << k << endl;
  cout.flush();
  bool done = false;
  while (!done) {
    int x;
    cin >> x;
    if (x == -1) {
      for (int i = 1; i < MAXN; i += 3) {
        if (used[i] == -1 && used[i + 1] == -1) used[i] = (i + 2) / 3 * 2;
      }
      REP(i,0,MAXN) if (used[i] != -1) cout << i << " ";
      cout << endl;
      done = true;
    }
    else {
      if (used[x] != -1) cout << used[x] << endl;
      else if (x % 3) {
        used[x / 3 * 3 + ((x % 3) ^ 3)] = (x + 2) / 3 * 2;
        cout << -1 << endl;
      }
      else return 1;
    }
    cout.flush();
  }
  return 0;
}
