// ––– CodeForces Contest 1070, Problem K: "Video Posts" –––

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

  int n, k;
  cin >> n >> k;

  int arr[n], sm = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr[i] = x;
    sm += x;
  }
  if (sm % k) {
    cout << "No" << '\n';
    return 0;
  }
  sm /= k;

  int a = 0, ans[k];
  memset(ans, 0, sizeof ans);
  int l = -1;
  for (int i = 0; i < k; i++) {
    int a = 0, b = 0;
    for (; a < sm; a += arr[l]) {
      l++, b++;
    }
    if (a != sm) {
      cout << "No" << '\n';
      return 0;
    }
    ans[i] = b;
  }

  cout << "Yes" << '\n';
  for (auto& x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
}
