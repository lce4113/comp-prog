// ––– CodeForces Contest 875, Problem A: "Classroom Watch" –––

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

  vi ans;
  for (int i = 1; i <= 100; i++) {
    int a = 0, x = n - i;
    while (x > 0) {
      a += (x % 10);
      x /= 10;
    }
    if (a == i) {
      ans.pb(n - i);
    }
  }

  sort(ans.begin(), ans.end());

  cout << ans.size() << '\n';
  for (auto& x : ans) {
    cout << x << '\n';
  }
}
