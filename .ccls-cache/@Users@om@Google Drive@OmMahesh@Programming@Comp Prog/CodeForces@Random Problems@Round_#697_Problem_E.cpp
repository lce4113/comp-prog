// ––– HEADER –––

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
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    sort(a, a + n);

    int knap[2001];
    memset(knap, 0, sizeof knap);
    knap[0] = 1;
    for (int i = 0; i < k; i++) {
      for (int l = 0; l < n; l++) {
        knap[i + a[l]] += knap[i];
      }
    }

    cout << knap[k] << endl;
  }
}
