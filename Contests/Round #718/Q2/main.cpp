// ––– Round #718: Problem B –––

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
using pli = pair<ll, int>;
using vi = vector<int>;
using vl = vector<ll>;

bool compare(pli l, pli r)
{
  return l.f < r.f;
}

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n >> m;

    ll arr[100][100];
    pli mins[n * m];
    for (int k = 0; k < n; k++) {
      for (int l = 0; l < m; l++) {
        ll elt;
        cin >> elt;
        arr[k][l] = elt;
        mins[k * m + l] = mp(elt, k * m + l);
      }
    }

    sort(mins, mins + n * m, compare);

    for (int k = 0; k < m; k++) {
      int pos = mins[k].s;
      int posx = pos / n;
      int posy = pos % m;
      ll temp = arr[posx][k];
      for (int l = 0; l < m; l++) {
        if (l != k && mins[l].s == posx * m + k) {
          mins[l].s = pos;
          break;
        }
      }
      arr[posx][k] = arr[posx][posy];
      arr[posx][posy] = temp;
    }

    for (int k = 0; k < n; k++) {
      for (int l = 0; l < m; l++) {
        cout << arr[k][l] << ' ';
      }
      cout << endl;
    }
    cout << endl;
  }
}
