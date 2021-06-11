// ––– CodeForces Educational Round 110: Problem B –––

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

int lg(int n) {
  int m = n;
  for (int i = sqrt(n); i >= 2; i--) {
    if (n % i == 0) {
      m = i;
    }
  }
  return m;
}

bool cmp(int a, int b) {
  if (a == 1) return false;
  if (b == 1) return true;
  return lg(a) < lg(b);
}

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

    sort(arr, arr+n, cmp);

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int k = i + 1; k < n; k++) {
        if (gcd(arr[i], 2*arr[k]) != 1) ans++;
      }
    }

    cout << ans << '\n';
  }
}
