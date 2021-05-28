// ––– CodeForces "Even Substrings": Problem A –––

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

  int n;
  cin >> n;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    if (x % 2 == 0)
      ans += i + 1;
  }

  cout << ans << '\n';
}
