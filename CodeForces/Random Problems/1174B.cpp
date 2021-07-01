// ––– CodeForces Contest 1174, Problem B: "Ehab is an Odd Person" –––

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

  int arr[n], a = -1;
  bool b = false;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr[i] = x;
    if (a == -1) {
      a = (x) % 2;
    } else if (a != x % 2) {
      b = true;
    }
  }

  if (b == false) {
    goto done;
  }

  sort(arr, arr + n);

done:
  for (auto& x : arr) {
    cout << x << ' ';
  }
  cout << '\n';
}
