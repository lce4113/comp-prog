// ––– CodeForces Round #724: Problem B –––

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

str alph = "abcdefghijklmnopqrstuvwxyz";

str atos(int n, int ans[])
{
  str S = "";
  for (int i = n - 1; i >= 0; i--) {
    if (ans[i] != 0) {
      S += alph.substr(ans[i] - 1, 1);
    }
  }
  return S;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    str m;
    cin >> m;

    int ans[n];
    memset(ans, 0, sizeof ans);
    while (true) {
      bool B = false;
      str S = atos(n, ans);
      for (int k = 0; k < n - S.length() + 1; k++) {
        /* cout << m.substr(k, S.length()) << ' ' << S << '\n'; */
        if (m.substr(k, S.length()) == S) {
          B = true;
          break;
        }
      }
      if (!B)
        break;
      ans[0]++;
      int a = 0;
      while (ans[a] == 27) {
        ans[a] = 0;
        a++;
        ans[a]++;
      }
    }

    cout << (atos(n, ans)) << '\n';
  }
}
