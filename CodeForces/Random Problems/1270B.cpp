// ––– CodeForces Contest 1270, Problem B: "Interesting Subarray" –––

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
    for (int i = 0; i < n - 1; i++) {
      if (abs(arr[i + 1] - arr[i]) >= 2) {
        cout << "YES" << '\n';
        cout << i + 1 << ' ' << i + 2 << '\n';
        goto done;
      }
    }

    cout << "NO" << '\n';
done:
    continue;
  }
}
