#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
using namespace std ;
int verbose ;
struct e {
   int v, flow, c, rev ;
} ;
struct g {
   int v ;
   vector<vector<e>> adj ;
   vector<int> level ;
   g(int v_) : v(v_), adj(v_), level(v_) {}
   void addedge(int a, int b, int c) {
 if (verbose) cout << "Add edge " << a << " " << b << " " << c << endl ;
      e ab {b,0,c,(int)adj[b].size()} ;
      e ba {a,0,0,(int)adj[a].size()} ;
      adj[a].push_back(ab) ;
      adj[b].push_back(ba) ;
   }
   int bfs(int s, int t);
   int sendflow(int s, int flow, int t, vector<int> &ptr) ;
   int dinic(int s, int t) ;
} ;
int g::bfs(int s, int t) {
   for (auto &v : level)
      v = -1 ;
   level[s] = 0 ;
   vector<int> q ;
   q.push_back(s) ;
   for (int qg=0; qg<(int)q.size(); qg++) {
      int a = q[qg] ;
      for (auto &e:adj[a])
         if (level[e.v] < 0 && e.flow < e.c) {
            level[e.v] = level[a]+1 ;
            q.push_back(e.v) ;
         }
   }
   return level[t] >= 0 ;
}
int g::sendflow(int a, int flow, int t, vector<int> &start) {
   if (a == t)
      return flow ;
   for (; start[a]<(int)adj[a].size(); start[a]++) {
      e &e = adj[a][start[a]] ;
      if (level[e.v] == level[a]+1 && e.flow < e.c) {
         int curf = min(flow, e.c-e.flow) ;
         int tempf = sendflow(e.v, curf, t, start) ;
         if (tempf > 0) {
            e.flow += tempf ;
            adj[e.v][e.rev].flow -= tempf ;
            return tempf ;
         }
      }
   }
   return 0 ;
}
int g::dinic(int s, int t) {
   if (s == t)
      return -1 ;
   int tot = 0 ;
   vector<int> start(v+1) ;
   while (bfs(s, t)) {
      for (auto &v : start)
         v = 0 ;
      while (int f=sendflow(s, INT_MAX, t, start))
         tot += f ;
   }
   return tot ;
}
const int MAX = 512 ;
vector<pair<int, int>> ab ;
int used[MAX], n, k, adj[MAX][MAX], parity[MAX] ;
vector<int> seq ;
int check(int togo, int k) {
   if (k < 0 || k > togo)
      return 0 ;
   int gn = togo + 2 ;
   int lastone = -1 ;
   if (seq.size()) {
      lastone = seq[seq.size()-1] ;
      int other = 0 ;
      for (int i=0; i<n; i++)
         if (!used[i] && adj[lastone][i])
            other++ ;
      if (other) {
         used[lastone]-- ;
         gn++ ;
      } else {
 if (verbose) cout << "killing use of " << lastone << endl ;
         lastone = -1 ;
      }
   }
   g g(gn) ;
   int mapped[MAX] ;
   int at = 1 ;
   for (int i=0; i<n; i++)
      if (used[i] == 0)
         mapped[i] = at++ ;
   int cnt[2] ;
   int edges = 0 ;
   cnt[0] = cnt[1] = 0 ;
   for (int i=0; i<n; i++)
      if (used[i] == 0) {
         int wt = 2 ;
         if (i == lastone)
            wt-- ;
         if (parity[i] == 1) {
            g.addedge(0, mapped[i], wt) ;
            for (int j=0; j<n; j++)
               if (!used[j] && adj[i][j]) {
                  g.addedge(mapped[i], mapped[j], 1) ;
                  edges++ ;
               }
            cnt[0]++ ;
         } else {
            g.addedge(mapped[i], gn-1, wt) ;
            cnt[1]++ ;
         }
      }
   if (k > edges)
      return 0 ;
   if (k == 0 && edges > 0 && edges == cnt[0] * cnt[1])
      return 0 ;
   int mf = g.dinic(0, gn-1) ;
 if (verbose) cout << "In check with togo " << togo << " mf " << mf << " k " << k << endl ;
   if (lastone >= 0)
      used[lastone]++ ;
   return mf >= k ;
}
int recur(int togo, int k, int prev) {
 if (verbose) cout << "In recur " << togo << " " << k << " " << prev << endl ;
   if (togo == 0)
      return k == 0 ;
   if (k < 0 || !check(togo, k))
      return 0 ;
   for (int i=0; i<n; i++)
      if (used[i] == 0) {
         used[i] = 1 ;
         int nk=k ;
         if (prev >= 0 && adj[prev][i])
            nk-- ;
         seq.push_back(i) ;
         if (recur(togo-1, nk, i))
            return 1 ;
         seq.pop_back() ;
         used[i] = 0 ;
      }
   return 0 ;
}
void asper(int at, int par) {
   if (parity[at] != 0)
      return ;
   parity[at] = 1 + par ;
   for (int i=0; i<n; i++)
      if (adj[at][i])
         asper(i, 1-par) ;
}
int main(int argc, char *[]) {
   verbose = argc > 1 ;
   cin >> n >> k ;
   k = n - 1 - k ;
   ab.resize(n-1) ;
   for (auto &p: ab) {
      cin >> p.first >> p.second ;
      p.first-- ;
      p.second-- ;
      adj[p.first][p.second] = 1 ;
      adj[p.second][p.first] = 1 ;
   }
   asper(0, 0) ;
   if (0 == recur(n, k, -1))
      cout << -1 << endl ;
   else {
      const char *sep = "" ;
      for (auto v: seq) {
         cout << sep << 1+v ;
         sep = " " ;
      }
      cout << endl ;
   }
}
