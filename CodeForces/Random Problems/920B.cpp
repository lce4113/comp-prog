// ––– CodeForces Contest 920, Problem B: "Tea Queue" –––

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

    pair<int, int> arr[n];
    for (int i = 0; i < n; i++) {
      int a;
      int b;
      cin >> a >> b;
      arr[i] = mp(a, b);
    }

    int a = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i].s < a + 1) {
        cout << 0 << ' ';
        continue;
      }
      a = max(arr[i].f, a + 1);
      cout << a << ' ';
    }
    cout << '\n';
  }
}
