// ––– USACO 2018 January Bronze: Problem B –––

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

int n;

int count(pi arr[], int r) {
  int a, b, ans = 0;
  if (r == 0) a = arr[1].f, b = arr[1].s;
  else a = arr[0].f, b = arr[0].s;
  for (int i = 1; i < n; i++) {
    if (r == i) continue;
    if (arr[i].f <= b) b = arr[i].s;
    else {
      ans += b - a;
      a = arr[i].f;
      b = arr[i].s;
    }
  }
  ans += b - a;
  return ans;
}

int main()
{
  ifstream cin("lifeguards.in");
  ofstream cout("lifeguards.out");

  cin >> n;

  pair<int, int> arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i].f >> arr[i].s;
  }

  sort(arr, arr+n);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int len = count(arr, i);
    if (len > ans) ans = len;
  }

  cout << ans;
}
