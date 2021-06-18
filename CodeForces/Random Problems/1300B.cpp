// ––– CodeForces Contest 1300, Problem B: "Assigning to Classes" –––

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

    int arr[2 * n];
    for (int i = 0; i < 2 * n; i++) {
      int x;
      cin >> x;
      arr[i] = x;
    }

    sort(arr, arr + 2 * n);

    cout << arr[n] - arr[n - 1] << '\n';
  }
}
