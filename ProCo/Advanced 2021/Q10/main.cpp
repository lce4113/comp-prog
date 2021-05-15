// ––– ProCo Advanced 2021: Problem J –––

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
    int a, b, c;
    cin >> a >> b >> c;

    int sum = a + b + c;
    int m = max({ a, b, c });
    if (sum - m <= m) {
      cout << "No" << '\n';
      continue;
    }
    cout << "Yes" << '\n';
  }
}
