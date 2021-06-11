// ––– CodeForces "Exam in BerSU (easy version)": Problem C1 –––

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

  int n, M;
  cin >> n >> M;

  int arr[n], pfs[n + 1];
  pi arr2[n];
  pfs[0] = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr[i] = x;
    arr2[i] = mp(x, i);
    pfs[i + 1] = pfs[i] + x;
  }

  sort(arr2, arr2 + n);

  for (int i = 0; i < n; i++) {
    int x = pfs[i + 1];
    int d = n;
    for (int k = 0;; k++) {
      if (x <= M) {
        cout << k << ' ';
        break;
      }
      for (int l = n - 1;; l--) {
        if (l < d && arr2[l].s < i) {
          d = l;
          x -= arr2[l].f;
          break;
        }
      }
    }
  }
}
