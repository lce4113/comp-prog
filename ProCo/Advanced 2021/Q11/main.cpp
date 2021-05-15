// ––– ProCo Advanced 2021: Problem K –––

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

int dp[500][500];

void checkW(deque<char>& mn, int& ans)
{
  while (!mn.empty() && mn.front() == 'W') {
    ans++;
    mn.pop_front();
  }
  while (!mn.empty() && mn.back() == 'W') {
    ans++;
    mn.pop_back();
  }
}

int dig(deque<char> mn, int ans, int k, int forb, int a, int b)
{
  int e = dp[a][b];
  if (e != 0)
    return e;

  if (forb == 0) {
    mn.pop_front();
  } else if (forb == 1) {
    mn.pop_back();
  }
  checkW(mn, ans);

  if (k == 0)
    return ans;

  int ans1 = -1, ans2 = -1;
  if (!mn.empty()) {
    ans1 = dig(mn, ans, k - 1, 0, a + 1, b);
  }
  if (!mn.empty()) {
    ans2 = dig(mn, ans, k - 1, 1, a, b + 1);
  }

  int asdf;
  if (ans1 != -1 && ans2 != -1) {
    asdf = max({ ans1, ans2 });
  } else if (ans1 != -1) {
    asdf = ans1;
  } else if (ans2 != -1) {
    asdf = ans1;
  } else {
    asdf = ans;
  }

  dp[a][b] = asdf;
  return asdf;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  deque<char> mn;
  for (int i = 0; i < n; i++) {
    char m;
    cin >> m;
    mn.push_back(m);
  }

  int ans = dig(mn, 0, k, 2, 0, 0);

  cout << ans << '\n';
}
