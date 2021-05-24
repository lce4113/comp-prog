// ––– USACO 2017 February Bronze: Problem C –––

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
  ifstream cin("cowqueue.in");
  ofstream cout("cowqueue.out");

  int n;
  cin >> n;

  pair<int, int> arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i].f >> arr[i].s;
  }

  sort(arr, arr + n);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max({arr[i].f, ans}) + arr[i].s;
  }

  cout << ans << '\n';
}
