// ––– CodeForces Round #731: Problem E –––

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
    int k, n;
    cin >> k >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[i] = x;
    }

    int b[n];
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      b[i] = x;
    }

    int arr[k], ans[k];
    memset(arr, 0, sizeof arr);
    memset(ans, 0, sizeof ans);
    multiset<int> l, r;
    for (int i = 0; i < n; i++) {
      arr[a[i] - 1] = b[i];
      r.insert(b[i] + a[i] - 1);
    }

    for (int i = 0; i < k; i++) {
      if (arr[i]) {
        r.erase(r.lower_bound(arr[i] + i));
        l.insert(arr[i] + k - i - 1);
      }
      if (l.size() == 0) {
        ans[i] = *r.begin() - i;
      } else if (r.size() == 0) {
        ans[i] = *l.begin() - k + i + 1;
      } else {
        ans[i] = min(*l.begin() - k + i + 1, *r.begin() - i);
      }
    }

    for (auto& x : ans) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}
