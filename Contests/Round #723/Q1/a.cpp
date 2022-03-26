// ––– CodeForces Round #723: Problem A –––

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

const int MAXN = 25;

int n;
int arr[2 * MAXN], diffs[2 * MAXN - 1];

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;

    for (int i = 0; i < 2 * n; i++) {
      cin >> arr[i];
    }

    sort(arr, arr + 2 * n);

    int ans[2 * n];
    for (int i = 0; i < 2 * n; i++) {
      if (i % 2 == 0) {
        ans[i] = arr[i / 2];
      } else {
        ans[i] = arr[2 * n - i / 2 - 1];
      }
    }

    for (int i = 0; i < 2 * n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}
