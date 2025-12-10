#include <iostream>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <unordered_map>

typedef std::pair<int, int> player;
typedef std::vector<player> group;
typedef std::vector<std::unordered_map<int, int> > graph;

constexpr int teamsize = 15;

bool bfs(const graph &g, int s, int t, std::vector<int> &parent)
{
  int N = g.size();
  std::vector<bool> visited(N);
  parent.resize(N);
  std::queue <int> q;
  q.push(s);
  visited[s] = true;
  parent[s] = -1;

  while (!q.empty())
    {
      int u = q.front();
      q.pop();

      for (auto v : g[u])
      {
        if (!visited[v.first] && v.second > 0)
        {
          q.push(v.first);
          parent[v.first] = u;
          visited[v.first] = true;
        }
      }
    }

  return visited[t];
}

int fordFulkerson(const graph &g, int s, int t)
{
  int N = g.size();
  graph rGraph = g;

  std::vector<int> parent(N);

  int max_flow = 0;

  while (bfs(rGraph, s, t, parent))
    {    
      for (int v=t; v != s; v=parent[v])
        {
          int u = parent[v];
          rGraph[u][v] -= 1;
          rGraph[v][u] += 1;
        }

      max_flow += 1;
    }

  return max_flow;
} 


bool compatible(group &g1, group &g2)
{
    int s1 = g1.size();
    int s2 = g2.size();
    if(s1 + s2 != teamsize)
        return false;
    
    graph g(2*teamsize+2);
    for(int i=0; i<teamsize; i++)
    {
        g[0][i+2] = 1;
        g[teamsize+2+i][1] = 1;
    }
    int idx=0;
    for(int i=0; i<s1; i++)
    {
        g[2+idx][teamsize+2+g1[i].first] = 1;
        g[2+idx][teamsize+2+g1[i].second] = 1;
        idx++;
    }
    for(int i=0; i<s2; i++)
    {
        g[2+idx][teamsize+2+g2[i].first] = 1;
        g[2+idx][teamsize+2+g2[i].second] = 1;
        idx++;
    }
    return fordFulkerson(g, 0, 1) == teamsize;
}

int main()
{
    std::vector<group> oddgroups;
    std::vector<group> evengroups;
    int n;
    std::cin >> n;
    for(int i=0; i<n; i++)
    {
        group g;
        int k;
        std::cin >> k;
        for(int j=0; j<k; j++)
        {
            int a, b;
            std::cin >> a >> b;
            player p{a-1, b-1};
            g.push_back(p);
        }
        if(k % 2)
            oddgroups.push_back(g);
        else
            evengroups.push_back(g);
    }
    
    graph g(2+n);
    int os = oddgroups.size();
    int es = evengroups.size();
    for(int i=0; i<os; i++)
    {
        g[0][i+2] = 1;
    }
    for(int i=0; i<es; i++)
    {
        g[i+2+os][1] = 1;
    }
    for(int i=0; i<os; i++)
    {
        for(int j=0; j<es; j++)
        {
            if(compatible(oddgroups[i], evengroups[j]))
            {
                g[i+2][j+2+os] = 1;
            }
        }
    }
    std::cout << fordFulkerson(g, 0, 1) << std::endl;
}
