// ––– CodeForces Round #479: Problem C –––

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
  cin.tie(0)->sync_with_stdio(0);

  ll n, k;
  cin >> n >> k;

  ll arr[n];
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    arr[i] = x;
  }

  sort(arr, arr + n);

  if (k == 0) {
    if (arr[0] > 1) {
      cout << arr[0] - 1 << '\n';
    } else {
      cout << -1 << '\n';
    }
  } else if (arr[k - 1] == arr[k]) {
    cout << -1 << '\n';
  } else {
    cout << arr[k - 1] << '\n';
  }
}
