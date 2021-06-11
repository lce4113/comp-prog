// ––– CodeForces Round #579: Problem B –––

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

    map<int, int> a;
    for (int i = 0; i < 4 * n; i++) {
      int x;
      cin >> x;
      if (a[x])
        a[x]++;
      else
        a[x] = 1;
    }

    vi b;
    bool B = false;
    for (auto& x : a) {
      if (x.s % 2 != 0) {
        B = true;
        break;
      }
      for (int i = 0; i < x.s / 2; i++) {
        b.pb(x.f);
      }
    }
    if (B) {
      cout << "NO" << '\n';
      continue;
    }

    sort(b.begin(), b.end());

    int c = b[0] * b[2 * n - 1];
    for (int i = 1; i < n; i++) {
      if (b[i] * b[2 * n - i - 1] != c) {
        goto done;
      }
    }

    cout << "YES" << '\n';
    continue;
  done:
    cout << "NO" << '\n';
  }
}
