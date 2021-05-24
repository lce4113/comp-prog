// ––– USACO 2016 US Open Bronze: Problem C –––

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
  ifstream cin("reduce.in");
  ofstream cout("reduce.out");

  int n;
  cin >> n;

  pair<int, int> arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i].f >> arr[i].s;
  }

  int lowx = 0, highx = 0;
  int lowy = 0, highy = 0;
  for (int k = 1; k < n; k++) {
    if (arr[k].f < arr[lowx].f) lowx = k;
    if (arr[k].f > arr[highx].f) highx = k;
    if (arr[k].s < arr[lowy].s) lowy = k;
    if (arr[k].s > arr[highy].s) highy = k;
  }

  ll ans = 100'000'000'000;
  for (int i : {lowx, lowy, highx, highy}) {
    lowx = 50'000, highx = -1;
    lowy = 50'000, highy = -1;
    for (int k = 0; k < n; k++) {
      if (k == i) continue;
      if (arr[k].f < lowx) lowx = arr[k].f;
      if (arr[k].f > highx) highx = arr[k].f;
      if (arr[k].s < lowy) lowy = arr[k].s;
      if (arr[k].s > highy) highy = arr[k].s;
    }
    /* cout << highx << ' ' << lowx << ' ' << highy << ' ' << lowy << '\n'; */
    int tmp = (highx - lowx) * (highy - lowy);
    if (tmp < ans) ans = tmp;
  }

  cout << ans;
}
