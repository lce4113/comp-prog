// ––– CodeForces Round #722: Problem A –––

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

    int arr[n], mn = 100;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x < mn)
        mn = x;
      arr[i] = x;
    }

    int ans = n;
    for (int i = 0; i < n; i++) {
      if (mn == arr[i])
        ans--;
    }

    cout << ans << '\n';
  }
}
