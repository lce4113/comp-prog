// ––– CodeForces Round #725: Problem B –––

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

    int arr[n], sm = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      arr[i] = x;
      sm += x;
    }

    if (sm % n != 0) {
      cout << -1 << '\n';
      continue;
    }

    int avg = sm / n, ans = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] > avg)
        ans++;
    }

    cout << ans << '\n';
  }
}
