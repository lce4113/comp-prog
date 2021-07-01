// ––– CodeForces Contest 1293, Problem A: "ConneR and the A.R.C. Markland-N" –––

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
    int n, s, k;
    cin >> n >> s >> k;

    set<int> a;
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      a.insert(x);
    }

    int i = s;
    while (a.count(i) != 0 && i < n + 1) {
      i++;
    }
    int ans = i;

    i = s;
    while (a.count(i) != 0 && i > 0) {
      i--;
    }
    if (i != 0 && (ans == n + 1 || abs(i - s) < abs(ans - s))) {
      ans = i;
    }

    cout << abs(ans - s) << '\n';
  }
}
