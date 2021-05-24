// ––– USACO 2016 February Bronze: Problem B –––

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
  ifstream cin("cbarn.in");
  ofstream cout("cbarn.out");

  int n;
  cin >> n;

  int r[n];
  for (int i = 0; i < n; i++) {
    cin >> r[i];
  }

  int ans = 1'000'000'000;
  for (int i = 0; i < n; i++) {
    int dist = 0;
    for (int k = 1; k < n; k++) {
      dist += k * r[(i + k) % n];
    }
    if (dist < ans) ans = dist;
  }

  cout << ans << '\n';
}
