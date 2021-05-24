// ––– CodeForces Round #721: Problem B2 –––

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

map<str, int> dp;

int calc(int n, str arr, int c)
{
  if (c != -1) {
    arr.replace(c, 1, "1");
  }

  int asdf = dp[arr];
  if (asdf)
    return asdf;

  int ans;
  for (int i = 0; i < n; i++) {
    if (arr[i] == '0')
      ans = calc(n, arr, i);
  }

  dp[arr] = ans;
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

    char arr[n];
    int num = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] == '0')
        num++;
    }

    int ans = calc(n, arr, -1);
    switch (ans) {
    case 0:
      cout << "ALICE" << '\n';
      break;
    case 1:
      cout << "BOB" << '\n';
      break;
    case 2:
      cout << "DRAW" << '\n';
      break;
    }
  }
}
