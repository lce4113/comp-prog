// ––– CodeForces Contest 1365, Problem A: "Matrix Game" –––

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
    int n, m;
    cin >> n >> m;

    set<int> cols, rows;
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < m; k++) {
        int x;
        cin >> x;
        if (x) {
          cols.insert(k);
          rows.insert(i);
        }
      }
    }

    int ans = min(m - cols.size(), n - rows.size());
    cout << (ans % 2 == 0 ? "Vivek" : "Ashish") << '\n';
  }
}
