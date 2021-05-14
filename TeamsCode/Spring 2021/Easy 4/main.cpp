// ––– TeamsCode Spring 2021 Easy #4 –––

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

bool check(int n, str s)
{
  for (int i = 0; i < n; i++) {
    if (s[i] != s[n - i - 1]) {
      return false;
    }
  }
  return true;
}

int main()
{
  int t;
  cin >> t;

  int ans = 0;
  for (int i = 0; i < t; i++) {
    str a;
    cin >> a;
    int n = a.length();
    for (int k = 1; k < n; k++) {
      str b = a.substr(0, k);
      str c = a.substr(k, n);
      if (check(k, b) && check(n - k, c)) {
        ans++;
        break;
      }
    }
  }

  cout << ans;
}
