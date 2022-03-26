// ––– Round #715: Problem D –––

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
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    char arr[3][2 * n];
    for (int k = 0; k < 3; k++) {
      for (int l = 0; l < 2 * n; l++) {
        cin >> arr[k][l];
      }
    }

    int a[6] = { 0, 0, 1, 1, 2, 2 };
    int b[6] = { 1, 2, 0, 2, 0, 1 };
    int max[2] = { 0, 0 };
    for (int k = 0; k < 6; k++) {
      for (int l = 0; l < 2 * n; l++) {
        bool boh = false;
        for (int m = 0; m <= l; m++) {
          char p1 = arr[a[k]][2 * n - 1 - l + m];
          char p2 = arr[b[k]][m];
          /* if (k == 1 && l == 1) { */
          /*   cout << p1 << ' ' << p2 << ' '; */
          /*   cout << endl; */
          /* } */
          /* cout << p1 << ' ' << p2 << ' '; */
          if (p1 != p2) {
            boh = true;
            break;
          }
        }
        if (!boh && l > max[0] - 1) {
          max[0] = l + 1;
          max[1] = k;
        }
      }
    }

    /* for (int k = 0; k < 2; k++) { */
    /*   cout << max[k] << ' '; */
    /* } */
    /* cout << endl; */

    char c;
    for (int k = 0; k < 4 * n - max[0]; k++) {
      if (k < 2 * n) {
        c = arr[a[max[1]]][k];
      } else {
        c = arr[b[max[1]]][k - 2 * n + max[0]];
      }
      cout << c;
    }
    cout << endl;
  }
}
