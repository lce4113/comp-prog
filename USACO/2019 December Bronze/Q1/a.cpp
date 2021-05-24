// ––– USACO 2019 December Bronze: Problem A –––

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

int m, n;
int gym[10][20];

bool check(int a, int b) {
  for (int i = 1; i < m; i++) {
    for (int k = 0; k < n; k++) {
      if (gym[i][k] == a) break;
      if (gym[i][k] == b) return false;
    }
  }
  return true;
}

int main()
{
  ifstream cin("gymnastics.in");
  ofstream cout("gymnastics.out");

  cin >> m >> n;

  for (int i = 0; i < m; i++) {
    for (int k = 0; k < n; k++) {
      cin >> gym[i][k];
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int k = i + 1; k < n; k++) {
      int a = gym[0][i];
      int b = gym[0][k];
      if (check(a, b)) ans++;
    }
  }

  cout << ans;
}
