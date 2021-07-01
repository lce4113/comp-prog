// ––– CodeForces Contest 1335, Problem C: "Two Teams Composing" –––

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
    int m = -1;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (a[x]) {
        a[x]++;
      } else {
        a[x] = 1;
      }
      m = max(m, a[x]);
    }

    if (m > a.size()) {
      cout << a.size() << '\n';
    } else if (m == a.size()) {
      cout << m - 1 << '\n';
    } else {
      cout << m << '\n';
    }
  }
}
