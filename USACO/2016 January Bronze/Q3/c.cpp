// ––– USACO 2016 January Bronze: Problem C –––

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
using str = string;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

int grass[2001][2001];

int main()
{
  ifstream cin("mowing.in");
  ofstream cout("mowing.out");

  int n;
  cin >> n;

  pi pos = mp(1000, 1000);
  int t = 1, ans = 100000;
  grass[1000][1000] = 1;
  for (int i = 0; i < n; i++) {
    char a;
    int b;
    cin >> a >> b;
    for (int k = 0; k < b; k++) {
      t++;

      switch (a) {
        case 'N':
          pos.s++;
          break;
        case 'S':
          pos.s--;
          break;
        case 'E':
          pos.f++;
          break;
        case 'W':
          pos.f--;
          break;
      }

      if (grass[pos.f][pos.s] != 0) {
        if (t - grass[pos.f][pos.s] < ans) {
          ans = t - grass[pos.f][pos.s];
        }
      }
      grass[pos.f][pos.s] = t;
      /* cout << pos.f << ' ' << pos.s << '\n'; */
    }
  }

  if (ans == 100000) cout << -1 << '\n';
  else cout << ans << '\n';
}
