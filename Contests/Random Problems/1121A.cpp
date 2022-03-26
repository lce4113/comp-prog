// ––– CodeForces Contest 1121, Problem A: "Technogoblet of Fire" –––

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

  int n, m, k;
  cin >> n >> m >> k;

  int arr1[n];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr1[i] = x;
  }

  int arr2[n], mx = -1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr2[i] = x;
    mx = max(mx, x);
  }

  set<int> arr3;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    arr3.insert(x);
  }

  int mxs[mx];
  memset(mxs, -1, sizeof mxs);
  for (int i = 0; i < n; i++) {
    if (mxs[arr2[i] - 1] == -1 || arr1[i] > arr1[mxs[arr2[i] - 1] - 1]) {
      mxs[arr2[i] - 1] = i + 1;
    }
  }

  int ans = k;
  for (int i = 0; i < mx; i++) {
    if (arr3.count(mxs[i])) {
      ans--;
    }
  }

  cout << ans << '\n';
}
