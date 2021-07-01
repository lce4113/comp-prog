// ––– CodeForces Contest 1339, Problem B: "Sorted Adjacent Differences" –––

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

    for (int i = n - 1; i >= 0; i--) {
      if (i % 2 == 0) {
        cout << arr[i / 2] << ' ';
      } else {
        cout << arr[n - i / 2 - 1] << ' ';
      }
    }
    cout << '\n';
  }
}
