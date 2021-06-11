// ––– CodeForces Round #712: Problem B –––

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

    char arr1[n];
    for (int i = 0; i < n; i++) {
      cin >> arr1[i];
    }
    char arr2[n];
    for (int i = 0; i < n; i++) {
      cin >> arr2[i];
    }

    int a = 0, b = 0, x = 0;
    for (int i = 0; i < n; i++) {
      if (x == 0) {
        if (arr1[i] == arr2[i])
          x = 1;
        else
          x = 2;
      } else if (x == 1) {
        if (arr1[i] != arr2[i]) {
          if (a != b) {
            goto done;
          }
          x = 2;
        }
      } else {
        if (arr1[i] == arr2[i]) {
          if (a != b) {
            goto done;
          }
          x = 1;
        }
      }
      if (arr1[i] == '0')
        a++;
      else
        b++;
    }
    if (x == 2 && a != b) {
      goto done;
    }

    cout << "YES" << '\n';
    continue;
  done:
    cout << "NO" << '\n';
  }
}
