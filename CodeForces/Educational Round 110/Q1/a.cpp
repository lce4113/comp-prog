// ––– CodeForces Educational Round 110: Problem A –––

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
    int arr[4];
    for (int i = 0; i < 4; i++) {
      cin >> arr[i];
    }

    int a = max(arr[0], arr[1]), b = max(arr[2], arr[3]);

    sort(arr, arr+4);

    if (min(a, b) != arr[2]) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }
}
