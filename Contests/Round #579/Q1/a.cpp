// ––– CodeForces Round #579: Problem A –––

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

bool a(int n, int arr[])
{
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] + 1 != arr[i + 1] && arr[i + 1] != 1) {
      return false;
    }
  }
  if (arr[n - 1] + 1 != arr[0] && arr[0] != 1) {
    return false;
  }
  return true;
}

bool b(int n, int arr[])
{
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] - 1 != arr[i + 1] && arr[i] != 1) {
      return false;
    }
  }
  if (arr[n - 1] - 1 != arr[0] && arr[n - 1] != 1) {
    return false;
  }
  return true;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      arr[i] = x;
    }

    if (a(n, arr) || b(n, arr)) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}
