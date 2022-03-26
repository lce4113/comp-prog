// ––– CodeForces Deltix Round Spring 2021: Problem A –––

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

    int arr[n];
    for (int i = 0; i < n; i++) {
      char x;
      cin >> x;
      arr[i] = x - '0';
    }

    int arr2[n];
    for (int i = 0; i < n; i++) {
      arr2[i] = arr[i];
    }
    for (int i = 0; i < m; i++) {
      bool b = false;
      if (!arr[0] && arr[1]) {
        arr2[0] = 1;
        b = true;
      }
      for (int i = 1; i < n - 1; i++) {
        if (!arr[i] && (arr[i-1]^arr[i+1])) {
          arr2[i] = 1;
          b = true;
        }
      }
      if (!arr[n-1] && arr[n-2]) {
        arr2[n-1] = 1;
        b = true;
      }
      if (!b) {
        break;
      }
      for (int i = 0; i < n; i++) {
        arr[i] = arr2[i];
      }
    }

    for (int i = 0; i < n; i++) {
      cout << arr[i];
    }
    cout << '\n';
  }
}
