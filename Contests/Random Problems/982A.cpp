// ––– CodeForces Contest 982, Problem A: "Row" –––

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

  if (n == 1) {
    char x;
    cin >> x;
    if (x == '0') {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
    return 0;
  }

  char arr[n];
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    arr[i] = x;
    if (i >= 1) {
      if (arr[i] == '1' && arr[i - 1] == '1') {
        cout << "NO" << '\n';
        return 0;
      }
    }
    if (i >= 2) {
      if (arr[i] == '0' && arr[i - 1] == '0' && arr[i - 2] == '0') {
        cout << "NO" << '\n';
        return 0;
      }
    }
  }
  if (n >= 2 && arr[0] == '0' && arr[1] == '0') {
    cout << "NO" << '\n';
    return 0;
  }
  if (n >= 2 && arr[n - 1] == '0' && arr[n - 2] == '0') {
    cout << "NO" << '\n';
    return 0;
  }
  cout << "YES" << '\n';
}
