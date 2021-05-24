// ––– CodeSprint Beginner 2021: Problem H –––

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

int check(int n, int r)
{
  if (n == 0)
    return r;
  int ans = 0;
  for (int i = 1; i <= r; i++) {
    int tmp = check(n - i, r + 1);
    if (tmp > ans)
      ans = tmp;
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

    int ans = check(n, 1);
    if (ans % 2 == 0)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
    /* int a = 1; */
    /* while (n > a) { */
    /*   n--; */
    /*   a++; */
    /* } */
    /* cout << 100 - t << ' '; */
    /* if (a % 2 == 0) */
    /*   cout << "NO" << '\n'; */
    /* else */
    /*   cout << "YES" << '\n'; */
  }
}
