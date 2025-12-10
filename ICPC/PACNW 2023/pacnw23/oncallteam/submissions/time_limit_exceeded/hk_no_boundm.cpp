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

#define MAXN 30005
#define MAXM 20

int N, M;
int pra[MAXM], prb[MAXN], dst[MAXM];
int L, adj[MAXM];
struct llist{
  int id, next;
  llist(){}
  llist(int _id, int _next){id=_id;next=_next;}
} lists[MAXM * MAXN];
void il(int a, int b){
  lists[L] = llist(b, adj[a]);
  adj[a] = L++;
}
bool bfs(){
  queue<int> que;
  REP(i,0,N){
    if(pra[i]==-1) { dst[i]=0; que.push(i); }
    else dst[i] = INF;
  }
  int maxdst = INF;
  bool aug = 0;
  while(!que.empty()){
    int x = que.front(); que.pop();
    if(dst[x]==maxdst) continue;
    int t = adj[x];
    while(t!=-1){
      int y = lists[t].id;
      if(prb[y]==-1){
        maxdst = dst[x];
        aug = 1;
      }else if(dst[prb[y]]==INF){
        dst[prb[y]] = dst[x]+1;
        que.push(prb[y]);
      }
      t = lists[t].next;
    }
  }
  return aug;
}
bool dfs(int x){
  int t = adj[x];
  while(t!=-1){
    int y = lists[t].id;
    if(prb[y]==-1 || (dst[prb[y]]==dst[x]+1 && dfs(prb[y]))){
      pra[x] = y;
      prb[y] = x;
      return true;
    }
    t = lists[t].next;
  }
  dst[x] = INF;
  return false;
}
int hk(){
  REP(i,0,N) pra[i] = -1;
  REP(i,0,M) prb[i] = -1;
  int ans = 0;
  while(bfs()){
    REP(i,0,N) if(pra[i]==-1) if(dfs(i)) ans++;
  }
  return ans;
}

char g[MAXN][MAXM + 1];
VI eng[MAXM], testMasks[MAXM + 1];
int t[MAXN], mapi[MAXN], mapj[MAXN];
int main() {
  int n, m;
  cin >> n >> m;
  REP(i,0,n) cin >> g[i];
  REP(j,0,m) {
    REP(i,0,n) if (g[i][j] == '1') eng[j].push_back(i);
  }
  REP(maskJob,0,1<<m) {
    int k = __builtin_popcount(maskJob);
    testMasks[k].push_back(maskJob);
  }

  int it = 0;
  int l = 0, r = m;
  while (l <= r) {
    int k = (l + r) / 2;
    bool ok = true;
    for (auto &maskJob: testMasks[k]) {
      ++it;
      N = 0; M = 0;
      REP(j,0,m) {
        if (!(maskJob & (1 << j))) continue;
        mapj[j] = N++;
        int cnt = 0;
        for (auto &i: eng[j]) {
          if (t[i] < it) {
            t[i] = it;
            mapi[i] = M++;
          }
          // if (++cnt >= m) break;
        }
      }
      L = 0; FILL(adj, -1);
      REP(j,0,m) {
        if (maskJob & (1 << j)) {
          int cnt = 0;
          for (auto &i: eng[j]) {
            il(mapj[j], mapi[i]);
            // if (++cnt >= m) break;
          }
        }
      }

      if (hk() < k) {
        ok = false;
        break;
      }
    }
    if (ok) l = k + 1;
    else r = k - 1;
  }
  cout << r << endl;
  return 0;
}
