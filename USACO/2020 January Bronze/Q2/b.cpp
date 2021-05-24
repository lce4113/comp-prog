// ––– USACO 2020 January Bronze: Problem B –––

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

bool has(vi vec, int elt) {
  for (int v : vec) {
    if (v == elt) return true;
  }
  return false;
}

int main()
{
  ifstream cin("photo.in");
  ofstream cout("photo.out");

  int n;
  cin >> n;

  int sums[n - 1];
  for (int i = 0; i < n - 1; i++) {
    cin >> sums[i];
  }

  vi arr;
  int last;
  for (int i = 1; i <= sums[0]; i++) {
    arr.pb(i);
    last = i;
    bool b = false;
    for (int k = 1; k < n; k++) {
      int elt = sums[k - 1] - last;
      if (elt < 1 || elt > n || has(arr, elt)) {
        b = true;
        break;
      }
      arr.pb(elt);
      last = elt;
    }
    if (!b) break;
    arr.clear();
  }

  for (int i = 0; i < n; i++) {
    if (i != 0) cout << ' ';
    cout << arr[i];
  }
}
