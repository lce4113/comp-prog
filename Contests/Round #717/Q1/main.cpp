// ––– Round #717: Problem A –––

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
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n >> m;
    int m2 = m;

    int arr[n];
    for (int k = 0; k < n; k++) {
      cin >> arr[k];
    }

    for (int k = 0; m2 > 0 && k < n; k++) {
      int mn = min(m2, arr[k]);
      arr[k] -= mn;
      m2 -= mn;
    }

    arr[n - 1] += m - m2;

    for (int k = 0; k < n; k++) {
      cout << arr[k] << ' ';
    }
    cout << endl;
  }
}
