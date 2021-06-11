// ––– CodeForces Deltix Round Spring 2021: Problem B –––

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

    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    cout << n*3 << '\n';
    for (int i = 1, k = 2; i < n; i += 2, k += 2) {
      for (int l = 0; l < 3; l++) {
        cout << 1 << ' ' << i << ' ' << k << '\n';
        cout << 2 << ' ' << i << ' ' << k << '\n';
      }
    }
  }
}
