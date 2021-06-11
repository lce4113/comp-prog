// ––– CodeForces Round #712: Problem C –––

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
    int n;
    cin >> n;

    char arr[n];
    int m;
    bool B = false;
    for (int i = 0; i < n; i++) {
      char x;
      cin >> x;
      arr[i] = x;
      if (!B && x == '0') {
        m = i;
        B = true;
      }
      if (x == '1') {
        B = false;
      }
    }

    str ans1, ans2;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      char x = arr[i];
      if (x == '0') {
        if (a == 0 && b == 0) {
          goto done;
        }
        if (a > b) {
          ans1 += ")";
          a--;
          ans2 += "(";
          b++;
        } else {
          ans1 += "(";
          a++;
          ans2 += ")";
          b--;
        }
      } else {
        if ((i == m - 1 && a <= 1 && b <= 1) || (a == 0 || b == 0)) {
          ans1 += "(";
          a++;
          ans2 += "(";
          b++;
        } else {
          ans1 += ")";
          a--;
          ans2 += ")";
          b--;
        }
      }
    }
    if (a != 0 || b != 0) {
      goto done;
    }

    cout << "YES" << '\n';
    cout << ans1 << '\n';
    cout << ans2 << '\n';
    continue;
  done:
    cout << "NO" << '\n';
  }
}
