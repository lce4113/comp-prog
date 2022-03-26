// ––– CodeForces "Make It Good": Problem C –––

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

    bool b = false;
    int ans = 0;
    for (int i = n - 1; i >= 1; i--) {
      if (b && arr[i] < arr[i - 1]) {
        ans = i;
        break;
      } else if (arr[i] > arr[i - 1]) {
        b = true;
      }
    }
    cout << ans << '\n';
  }
}
