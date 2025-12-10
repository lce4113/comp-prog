// ––– TeamsCode Spring 2021 Easy #3 –––

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
  ll n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    ll arr[m];
    for (int k = 0; k < m; k++) {
      cin >> arr[k];
    }
    sort(arr, arr + m);
    ll ans = arr[m - 1] * arr[m - 2];
    cout << ans << endl;
  }
}
