// ––– CodeForces Honest Coach: Problem B –––

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
      cin >> arr[i];
    }

    sort(arr, arr + n);

    int ans = 10000;
    for (int i = 1; i < n; i++) {
      int x = arr[i] - arr[i - 1];
      if (x < ans)
        ans = x;
    }

    cout << ans << '\n';
  }
}
