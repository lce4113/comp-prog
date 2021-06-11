// ––– CodeForces "Phoenix and Balance": Problem A –––

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

int pow2(int n)
{
  int ans = 1;
  for (int i = 0; i < n; i++) {
    ans *= 2;
  }
  return ans;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int a = pow2(n + 1) - 2;
    int b = pow2(n);
    int x = 2;
    for (int i = 1; i < n / 2; i++) {
      b += x;
      x *= 2;
    }

    cout << 2 * b - a << '\n';
  }
}
