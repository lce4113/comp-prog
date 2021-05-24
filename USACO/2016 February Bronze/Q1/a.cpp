// ––– USACO 2016 February Bronze: Problem A –––

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

int main()
{
  ifstream cin("pails.in");
  ofstream cout("pails.out");

  int X, Y, M;
  cin >> X >> Y >> M;

  int ans = 1000;
  for (int i = 0; i <= M/X; i++) {
    int m = X * i;
    while (m <= M) m += Y;
    m -= Y;
    if (M - m < ans) ans = M - m;
  }

  cout << M - ans << '\n';
}
