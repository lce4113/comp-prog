// ––– CodeForces Global Round 14: Problem C –––

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

int mn(int m, int sums[])
{
  int mn = 0;
  for (int i = 0; i < m; i++) {
    if (sums[i] < sums[mn])
      mn = i;
  }
  return mn;
}

bool cmp(int a, int b)
{
  return b > a;
}

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m, x;
    cin >> n >> m >> x;
    int arr[n];
    for (int k = 0; k < n; k++) {
      cin >> arr[k];
    }

    vi towers[m];
    multiset<pi> sums;

    for (int k = 0; k < m; k++) {
      sums.insert(mp(0, k));
    }

    int tb[n];
    for (int k = 0; k < n; k++) {
      int elt = arr[k];
      pi minTower = *sums.begin();
      towers[minTower.s].pb(elt);
      sums.erase(sums.begin());
      minTower.f += elt;
      sums.insert(minTower);
      tb[k] = minTower.s + 1;
    }

    int minH = (*sums.begin()).s;
    int maxH = (*sums.end()).s;
    if ((maxH - minH) > x) {
      cout << "NO" << endl;
      continue;
    }

    cout << "YES" << endl;
    for (int k = 0; k < n; k++) {
      cout << tb[k] << ' ';
    }
    cout << endl;
  }
}
