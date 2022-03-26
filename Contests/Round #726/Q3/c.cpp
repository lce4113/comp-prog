// ––– CodeForces Round #726: Problem C –––

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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      arr[i] = x;
    }

    sort(arr, arr + n);

    int ans[n];
    ans[0] = arr[n / 2 - 1];
    ans[n - 1] = arr[n / 2];
    for (int i = 1; i < n - 1; i++) {
      if (i % 2 == 0) {
        ans[i] = arr[i / 2 - 1];
      } else {
        ans[i] = arr[n - i / 2 - 1];
      }
    }

    if (n == 3) {
      if (arr[2] - arr[1] < arr[1] - arr[0]) {
        ans[0] = arr[1];
        ans[1] = arr[0];
        ans[2] = arr[2];
      }
    }

    for (auto& x : ans) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}
